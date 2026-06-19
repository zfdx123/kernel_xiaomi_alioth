# Xiaomi Alioth Kernel

Android 4.19 Non-GKI kernel tree for Redmi K40 / POCO F3 / Mi 11X
(`alioth` / `aliothin`).

## Status

- Linux upstream: `4.19.325`
- ACK branch: `android-4.19-stable`
- ACK extra branch: `android-trusty-4.19`
- Qualcomm/CLO tag: `LA.UM.9.12.r1-18500-SMxx50.QSSI14.0`
- Device platform: Xiaomi alioth, Qualcomm Kona / SM8250 family
- ZSTD: backported to `v1.5.5`
- Root compatibility: ReSukiSU manual-hook support
- CPUFreq default governor: Ondemand
- TCP congestion control: BBR2 is available and selected by alioth configs

## Defconfigs

- `arch/arm64/configs/alioth_defconfig`: main alioth build config.
- `arch/arm64/configs/alioth_hylab_defconfig`: hylab build config. It is
  synced additively from `alioth_defconfig`, preserving hylab-specific choices.

Both alioth configs enable `CONFIG_KSU_MANUAL_HOOK=y` and `CONFIG_KALLSYMS_ALL=y`
for ReSukiSU manual-hook compatibility. The old in-tree KernelSU driver entry is
removed; ReSukiSU integration is expected to use manual hooks, LSM hooks, and
input-handler hooks.

## Build

Use an LLVM/Clang based Android kernel toolchain:

```sh
make O=out ARCH=arm64 LLVM=1 LLVM_IAS=1 \
  CROSS_COMPILE=aarch64-linux-gnu- \
  CROSS_COMPILE_COMPAT=arm-linux-gnueabi- \
  alioth_defconfig

make O=out ARCH=arm64 LLVM=1 LLVM_IAS=1 \
  CROSS_COMPILE=aarch64-linux-gnu- \
  CROSS_COMPILE_COMPAT=arm-linux-gnueabi- \
  -j$(nproc)
```

For the hylab config, replace `alioth_defconfig` with
`alioth_hylab_defconfig`.

## Notes

- This tree carries Xiaomi device drivers and alioth-specific configuration.
- ReSukiSU manual hooks are wired into syscall, stat, reboot, read/write, input,
  and LSM-related paths.
- `CONFIG_KALLSYMS_ALL=y` is kept enabled to support static symbol lookup needed
  by ReSukiSU compatibility checks.
