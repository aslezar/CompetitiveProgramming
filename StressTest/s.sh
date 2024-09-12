# File names
MAIN_SOLUTION="a.cpp"
GENERATOR="gen.cpp"
# GENERATOR="gen_tree.cpp"
BRUTE_FORCE="brute.cpp"

# Compile the programs

g++ -DLOCAL_RUN -O2 -std=c++20 -I../ $MAIN_SOLUTION -o a.out
g++ -DLOCAL_RUN -O2 -std=c++20 -I../ $GENERATOR -o gen.out
g++ -DLOCAL_RUN -O2 -std=c++20 -I../ $BRUTE_FORCE -o brute.out

for((i=1; ; ++i)); do
    echo $i
    ./gen.out $i > inp
    # ./a.out < inp > out1
    # ./brute.out < inp > out2
    # diff -w out1 out2 || break
    diff -w <(./a.out < inp) <(./brute.out < inp) || break
done