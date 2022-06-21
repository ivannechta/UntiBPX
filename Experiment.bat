rem Analysed exe-files should be located in current folder.
rem Please check your IDA folder.

@echo off
for %%f in (*.exe) do (
"C:\Program Files (x86)\IDA Free\idag.exe" -SAnalyse.idc %%f
)
