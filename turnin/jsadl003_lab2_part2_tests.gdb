# Test file for "Lab2_introToAVR"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# test 1
test “NO WEIGHT”
setPINA 0x00
setPINB 0x00
setPINC 0x00
continue 5
expectPORTD 0x00
checkResult

#test 2
test “UNDER-WEIGHT”
setPINA 0x2E
setPINB 0x2E
setPINC 0x2E
continue 5
expectPORTD 0x00
checkResult

#test 3
test “OVERWEIGHT”
setPINA 0x32
setPINB 0x32
setPINC 0x32
continue 5
expectPORTD 0x01
checkResult

#test 4
test “UNDER-WEIGHT UNBALLENCED”
setPINA 0x78
setPINB 0x00
setPINC 0x00
continue 10
expectPORTD 0x02
checkResult

test “OVERWEIGHT UNBALLENCED”
setPINA 0x51
setPINB 0x3E
setPINC 0x00
continue 5
expectPORTD 0x03
checkResult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
