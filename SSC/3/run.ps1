gcc main.c -lm -o output 
if(Test-Path -Path '.\output.exe' -PathType Leaf) {
    .\output.exe
    Remove-Item -Path ".\output.exe" -Force
}