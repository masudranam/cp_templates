g++ -o sol sol.cpp
g++ -o brute brute.cpp
g++ -o gen gen.cpp
#for((i = 1; ; ++i)); do
for i in {1..300}; do
    echo $i
    ./gen $i > input
    # ./sol < int > out1
    # ./brute < int > out2
    # diff -w out1 out2 || break
    diff -w <(./sol < input) <(./brute < input) || break
done
