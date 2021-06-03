try 
{
    g++ "$args.cpp" -o $args -std=c++11

    # Get-Content input.txt | &.\"$args.exe" > output.txt
    &.\"$args.exe"

    rm "$args.exe"
}
catch
{
    exit
}