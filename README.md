# 🖼️ Computer Graphics TP

## 📂 Repository Structure

- **`base/`** → canonical project tree shared by all TP variants (original professor starter).
- **`variants/`** → sparse overlays with only the files that diverge per TP:
  - `variants/tp1` – updated `viewer/shaders/gpgpu_fullrt.comp`
  - `variants/tp2` – updated `viewer/shaders/gpgpu_fullrt.comp`
  - `variants/tp3` – updated `gpgpu_fullrt.comp`, `viewer/src/glshaderwindow.{h,cpp}`, `viewer/src/main.cpp`
- **`docs/`** → TP hand-outs (`TP1.pdf`, `TP2.pdf`, `TP3.pdf`, …).
- **`tp/`** → the three compute-shader variants that the run script can inject for quick testing.
- **`run.sh`** → helper that assembles a throwaway build directory, applies the selected overlay, swaps in the requested compute shader, then builds & launches the viewer.

## ▶️ How to Run

Pick the TP you want to try (1–3):

```bash
./run.sh <TP_number>
