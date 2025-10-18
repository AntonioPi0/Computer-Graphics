#include <QApplication>
#include <QGLFormat>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QActionGroup>
#include <QSignalMapper>
#include <QDir>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include "glshaderwindow.h"

static QSignalMapper sizeMapper;
static QSignalMapper shaderMapper;

void printUsage(const char *myname)
{
    fprintf(stderr, "\n");
    fprintf(stderr, "\n Usage    : %s [infile]\n", myname);
    exit(1);
}

void setupFileMenu(QMenuBar* myMenuBar, glShaderWindow* glWindow, QApplication *myApp)
{
    QMenu* fileMenu = myMenuBar->addMenu(myMenuBar->tr("&File"));
    // Open Scene
    QAction* openSceneAction = new QAction(myMenuBar->tr("&Open Scene"), fileMenu);
    openSceneAction->setShortcuts(QKeySequence::Open);
    openSceneAction->setStatusTip(myMenuBar->tr("&Opens an existing scene file"));
    glWindow->connect(openSceneAction, SIGNAL(triggered()), glWindow, SLOT(openSceneFromFile()));
    fileMenu->addAction(openSceneAction);
    // Load new texture
    QAction* openTextureAction = new QAction(myMenuBar->tr("&Load texture"), fileMenu);
    openTextureAction->setStatusTip(myMenuBar->tr("&Opens a new texture image file"));
    glWindow->connect(openTextureAction, SIGNAL(triggered()), glWindow, SLOT(openNewTexture()));
    fileMenu->addAction(openTextureAction);
    // Load new environment Map
    QAction* openEnvMapAction = new QAction(myMenuBar->tr("&Load environment map"), fileMenu);
    openEnvMapAction->setStatusTip(myMenuBar->tr("&Opens a new environment map file"));
    glWindow->connect(openEnvMapAction, SIGNAL(triggered()), glWindow, SLOT(openNewEnvMap()));
    fileMenu->addAction(openEnvMapAction);
    // Save screenshot
    QAction* saveImageAction = new QAction(myMenuBar->tr("&Save screenshot"), fileMenu);
    saveImageAction->setShortcuts(QKeySequence::Print);
    saveImageAction->setStatusTip(myMenuBar->tr("&Saves a copy of the screen to a file"));
    glWindow->connect(saveImageAction, SIGNAL(triggered()), glWindow, SLOT(saveScreenshot()));
    fileMenu->addAction(saveImageAction);
    // Fullscreen or just picture?
    QAction* toggleFullscreenAction = new QAction(myMenuBar->tr("&Full screen screenshot"), fileMenu);
    toggleFullscreenAction->setCheckable(true);
    toggleFullscreenAction->setStatusTip(myMenuBar->tr("&Save only the active window, or the entire screen"));
    glWindow->connect(toggleFullscreenAction, SIGNAL(changed()), glWindow, SLOT(toggleFullScreen()));
    fileMenu->addAction(toggleFullscreenAction);
    // Save Scene
    QAction* saveSceneAction = new QAction(myMenuBar->tr("&Save Scene"), fileMenu);
    saveSceneAction->setShortcuts(QKeySequence::Save);
    saveSceneAction->setStatusTip(myMenuBar->tr("&Saves current scene file"));
    glWindow->connect(saveSceneAction, SIGNAL(triggered()), glWindow, SLOT(saveScene()));
    fileMenu->addAction(saveSceneAction);
    // Quit program
    QAction* quitAction = new QAction(myMenuBar->tr("&Quit"), fileMenu);
    quitAction->setShortcuts(QKeySequence::Quit);
    quitAction->setStatusTip(myMenuBar->tr("&Quit program"));
    glWindow->connect(quitAction, SIGNAL(triggered()), myApp, SLOT(quit()));
    fileMenu->addAction(quitAction);
}

void setupWindowMenu(QMenuBar* myMenuBar, glShaderWindow* glWindow)
{
    QMenu* sizeMenu = myMenuBar->addMenu(myMenuBar->tr("&Window size"));
    // Window sizes.
    QStringList sizes = QStringList() << "640x480" << "800x600" <<
                                         "1024x768" << "1024x1024" << "1280x1024";
    QActionGroup* setSizeAction = new QActionGroup(sizeMenu);
    setSizeAction->setExclusive(true);
    foreach (const QString& sizeName, sizes) {
        QAction* action = setSizeAction->addAction(sizeName);
        action->setCheckable(true);
        if (sizeName == "640x480") action->setChecked(true);
        glWindow->connect(action, SIGNAL(triggered()), &sizeMapper, SLOT(map()));
        sizeMapper.setMapping(action, sizeName);
        sizeMenu->addAction(action);
    }

    glWindow->connect(&sizeMapper, SIGNAL(mapped(const QString&)), glWindow, SLOT(setWindowSize(const QString&)));
}

int main( int argc, char* argv[] )
{
    setlocale(LC_ALL,"C");
    QApplication app(argc, argv);
    QString sceneName = "teapot_wt.ply";
    QString textureName = "wildtextures-seamless-wood-planks.jpg";
    QString envMapName = "pisa.png";

    // Read scene name from arguments:
    QStringList arguments = app.arguments();
    for (int i = 1; i < arguments.size(); i++)
    {
        const QString& arg = arguments[i];
        if (i == 1 && !arg.startsWith("-")) {
            sceneName = arg;
        } else printUsage(argv[0]);
    }

    // Specify an OpenGL 4.4 format using the Core profile.
    // That is, no old-school fixed pipeline functionality
    QSurfaceFormat format;
    format.setSamples(16); // for anti-aliasing
    format.setDepthBufferSize(24);
    format.setVersion(4,4);
    format.setProfile(QSurfaceFormat::CoreProfile);

    // Create GL shader window and add it to application
    glShaderWindow *window = new glShaderWindow();
    window->setFormat(format);

    QString appPath = app.applicationDirPath();
    appPath = appPath + "/models/";
    window->setWorkingDirectory(appPath, sceneName, textureName, envMapName);
    // Embedding a QWindow in a QWidget, only way to combine it with widgets
    QWidget * container = QWidget::createWindowContainer(window);

    container->setMinimumSize(640, 480);
    container->setFocusPolicy(Qt::TabFocus);

    // Menu bar to be shared between all windows.
    QMenuBar *menuBar = new QMenuBar(container);
    menuBar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    setupFileMenu(menuBar, window, &app);
    setupWindowMenu(menuBar, window);
    QWidget* aux = window->makeAuxWindow();
    aux->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    QHBoxLayout *hb = new QHBoxLayout;
    hb->addWidget(aux);
    hb->addWidget(container);

    QVBoxLayout *vb = new QVBoxLayout;
    vb->addWidget(menuBar);
    vb->addLayout(hb);

    QWidget *w = new QWidget;
    w->move(200,100);
    w->setLayout(vb);
    w->show();

    return app.exec();
}
