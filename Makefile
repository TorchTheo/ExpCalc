CLASS=Number.cpp
TEST_CPP=tests/test.cpp
TEST_TARGET=test

test-Number:
	g++ -g -DNUMBER -o $(TEST_TARGET) $(CLASS) $(TEST_CPP)

clean:
	rm $(TEST_TARGET)