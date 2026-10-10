# Building GhostGirl System Watch

## Requirements

- **Windows 10 or 11** (VM is fine)
- **Visual Studio 2010**
- **Xbox 360 XDK** (official Microsoft developer kit)
- A jailbroken Xbox 360 for testing

> ⚠️ The official XDK is Windows-only and integrates with
> Visual Studio 2010. Newer Visual Studio versions do not work.

---

## Build Steps

1. Open `SystemWatch.sln` in Visual Studio 2010.
2. Set the target platform to **Xbox 360**.
3. Choose **Debug** or **Release**.
4. Build → produces `SystemWatch.xex`.
5. Copy `SystemWatch.xex` to the console:
   - Via FTP, or
   - Via USB stick
6. Place in `Hdd:\Apps\SystemWatch\SystemWatch.xex`.
7. Launch from your dashboard.

---

## Project Files (to be added)

These will be created when the Windows environment is set up:

- `SystemWatch.sln` — Visual Studio solution
- `SystemWatch.vcxproj` — project file
- `SystemWatch.vcxproj.filters` — file organization

---

## Notes

- Do not commit XDK files to this repo.
- Do not commit compiled `.xex` files to `src/` — put them in `releases/`.
- Test on real hardware before releasing.

---

## First Milestone

A build that:

1. Launches without crashing
2. Shows the app title on screen
3. Reads (placeholder) temperatures
4. Exits cleanly on the A button

After that, replace placeholder SMC calls with real ones.
