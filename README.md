# easyhook-examples
easyhook examples


- Injector2 一个命令行注入器
- wtl_dialog_target 目标进程，windows 窗体程序
- easyhook_dll_template 一个 windows api 拦截 dll
- messagebox_hook_dll  一个测试 easyhook 的简单例子

**注入例子**

```
injector2.exe --process-id 4312 --module-name messagebox_hook_dll-mt.dll --inject
injector2.exe --process-name wtl_dialog_target.exe --module-name messagebox_hook_dll-mt.dll --inject
injector2.exe --process-name wtl_dialog_target.exe --module-name easyhook_dll_template-mt.dll --inject
```


## links

- https://github.com/cuckoosandbox/cuckoo
- https://github.com/cuckoosandbox/monitor
- https://github.com/cuckoosandbox/cuckoomon