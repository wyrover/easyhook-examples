# easyhook-examples
easyhook examples


- Injector2 һ��������ע����
- wtl_dialog_target Ŀ����̣�windows �������
- easyhook_dll_template һ�� windows api ���� dll
- messagebox_hook_dll  һ������ easyhook �ļ�����

**ע������**

```
injector2.exe --process-id 4312 --module-name messagebox_hook_dll-mt.dll --inject
injector2.exe --process-name wtl_dialog_target.exe --module-name messagebox_hook_dll-mt.dll --inject
injector2.exe --process-name wtl_dialog_target.exe --module-name easyhook_dll_template-mt.dll --inject
```


## links

- https://github.com/cuckoosandbox/cuckoo
- https://github.com/cuckoosandbox/monitor
- https://github.com/cuckoosandbox/cuckoomon