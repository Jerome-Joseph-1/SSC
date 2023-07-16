# Check if main.l file exists
if (Test-Path -Path ".\main.l" -PathType Leaf) {
    flex main.l
}

# Check if main.y file exists
if (Test-Path -Path ".\main.y" -PathType Leaf) {
    bison -d main.y
}

# Check if lex.yy.c and main.tab.c files exist
if ((Test-Path -Path ".\lex.yy.c" -PathType Leaf) -and (Test-Path -Path ".\main.tab.c" -PathType Leaf)) {
    gcc lex.yy.c main.tab.c -o output
    Remove-Item -Path ".\lex.yy.c" -Force
    Remove-Item -Path ".\main.tab.c" -Force
}
# Check if lex.yy.c file exists
elseif (Test-Path -Path ".\lex.yy.c" -PathType Leaf) {
    gcc lex.yy.c -o output
    Remove-Item -Path ".\lex.yy.c" -Force
}
# Check if main.tab.c file exists
elseif (Test-Path -Path ".\main.tab.c" -PathType Leaf) {
    gcc main.tab.c -o output
    Remove-Item -Path ".\main.tab.c" -Force
}

# Check if output.exe file exists
if (Test-Path -Path ".\output.exe" -PathType Leaf) {
    .\output.exe
    Remove-Item -Path ".\output.exe" -Force
}


# if [ -f main.l]
# then
#     flex main.l
# fi

# if [ -f main.y]
# then
#     bison -d main.y
# fi 

# if [ -f lex.yy.c ] && [ -f main.tab.c ]
# then 
#     gcc lex.yy.c main.tab.c -o output 

# elif [ -f lex.yy.c ]
# then 
#     gcc lex.yy.c -o output

# elif [ -f main.tab.c ]
# then 
#     gcc main.tab.c -o output
# fi

# if [ -f output.exe ]
# then 
#     output.exe
#     rm output.exe
# fi
