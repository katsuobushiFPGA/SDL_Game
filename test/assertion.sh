./test | grep "Failure"
if [ $? -eq 1 ]; then
    ./test | grep "OK"
    echo "Test Success"
    exit 0;
else 
    echo "Test Failed"
    exit 1;
fi
