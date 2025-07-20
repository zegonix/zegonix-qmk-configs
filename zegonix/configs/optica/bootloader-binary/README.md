# Change Bootloader

When using a `JLink` you can use the `./commands.jlink` script to program the bootloader binary.
Use the following command:

```sh
JLinkExe -NoGui 1 -ExitOnError 1 -CommandFile commands.jlink
```

