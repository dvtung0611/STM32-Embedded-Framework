import json
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent

BOARDS_DIR = ROOT / "boards"

VSCODE_DIR = ROOT / ".vscode"

LAUNCH_FILE = VSCODE_DIR / "launch.json"

TASKS_FILE = VSCODE_DIR / "tasks.json"

launch_configurations = []

tasks = []

# =========================================================
# Generate per-board configurations
# =========================================================

for board_dir in BOARDS_DIR.iterdir():

    if not board_dir.is_dir():
        continue

    board_json = board_dir / "board.json"

    if not board_json.exists():
        continue

    with open(board_json, "r") as f:
        board = json.load(f)

    board_name = board["board"]

    # =====================================================
    # Build Task
    # =====================================================

    build_task = {
        "label": f"Build {board_name}",

        "type": "shell",

        "command": "make",

        "args": [
            f"BOARD={board_name}"
        ],

        "group": {
            "kind": "build",
            "isDefault": False
        },

        "problemMatcher": []
    }

    # =====================================================
    # Rebuild Task
    # =====================================================

    rebuild_task = {
        "label": f"Rebuild {board_name}",

        "dependsOrder": "sequence",

        "dependsOn": [
            "Clean build/",
            f"Build {board_name}"
        ]
    }

    tasks.append(build_task)

    tasks.append(rebuild_task)

    # =====================================================
    # Launch Configuration
    # =====================================================

    cfg = {
        "name": f"{board['name']} BareMetal Firmware Debug",

        "type": "cortex-debug",

        "request": "launch",

        "cwd": "${workspaceFolder}",

        "executable": (
            "${workspaceFolder}/build/"
            f"{board_name}/firmware.elf"
        ),

        "servertype": "openocd",

        "configFiles": [
            (
                "${workspaceFolder}/boards/"
                f"{board_name}/"
                f"{board['openocd_cfg']}"
            )
        ],

        "openOCDLaunchCommands": [
            f"hla_serial {board['serial']}"
        ],

        "device": board["mcu_device"],

        "svdFile": (
            "${workspaceFolder}/svd/"
            f"{board['svd']}"
        ),

        "runToEntryPoint": "main",

        "preLaunchTask": f"Rebuild {board_name}",

        "swoConfig": {
            "enabled": True,

            "cpuFrequency": board["cpu_frequency"],

            "swoFrequency": board["swo_frequency"],

            "source": "probe",

            "decoders": [
                {
                    "port": 0,
                    "type": "console",
                    "label": "ITM Console"
                }
            ]
        }
    }

    launch_configurations.append(cfg)

# =========================================================
# Common Tasks
# =========================================================

clean_task = {
    "label": "Clean build/",

    "type": "shell",

    "command": "make",

    "args": [
        "clean"
    ],

    "problemMatcher": []
}

tasks.insert(0, clean_task)

# =========================================================
# Final launch.json
# =========================================================

launch = {
    "version": "0.2.0",

    "configurations": launch_configurations
}

# =========================================================
# Final tasks.json
# =========================================================

tasks_json = {
    "version": "2.0.0",

    "tasks": tasks
}

# =========================================================
# Create .vscode directory
# =========================================================

VSCODE_DIR.mkdir(exist_ok=True)

# =========================================================
# Write launch.json
# =========================================================

with open(LAUNCH_FILE, "w") as f:
    json.dump(launch, f, indent=4)

# =========================================================
# Write tasks.json
# =========================================================

with open(TASKS_FILE, "w") as f:
    json.dump(tasks_json, f, indent=4)

# =========================================================
# Done
# =========================================================

print(f"Generated: {LAUNCH_FILE}")

print(f"Generated: {TASKS_FILE}")