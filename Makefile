CPP=Var.cpp utils.cpp Symbol.cpp Expr.cpp Calc.cpp const.cpp
TEST_CPP=tests/test.cpp
MAIN_CPP=main.cpp
TEST_TARGET=test
TARGET=calc

test-Number:
	g++ -g -DNUMBER -o $(TEST_TARGET) $(CPP) $(TEST_CPP)

test-Var:
	g++ -g -DVAR -o $(TEST_TARGET) $(CPP) $(TEST_CPP)

test-Exp:
	g++ -g -DEXP -o $(TEST_TARGET) $(CPP) $(TEST_CPP)

calc:
	g++ -g -o $(TARGET) $(CPP) $(MAIN_CPP)

# clean:
# 	rm $(TEST_TARGET)
clean:
	find . -type f -executable -delete