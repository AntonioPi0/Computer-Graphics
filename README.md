# 🖼️ Computer Graphics TP

## 📂 Repository Structure

- **`BVH_TP-master/`** → base code provided by the professor.
- **`TP/`** → contains 3 different versions of the file (`gpgpu_fullrt.comp`), one for each assigned TP.
- **`run.sh`** → a Bash script that:
  1. Takes an integer argument (1, 2, or 3) representing the TP version to run.
  2. Copies the selected version into the main directory as `gpgpu_fullrt.comp`.
  3. Builds the project.
  4. Runs the executable.

## ▶️ How to Run

To run a specific TP version:

```bash
./run.sh <TP_number>

