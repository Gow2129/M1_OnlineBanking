# Name of the project
PROJ_NAME = OnlineBanking
TEST_PROJ_NAME = Test_$(PROJ_NAME)

BUILD_DIR = Build

# All source code files
SRC =mainprogram.c\
src/methodfunction.c

# All test source files
TEST_SRC = test/test_OB.c\
unity/unity.c

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).$(EXEC)

# All include folders with header files
INC = -Iinc\
-Iunity\

#To check if the OS is Windows or Linux and set the executable file extension and delete command accordingly
ifdef OS
   RM = del /q
   FixPath = $(subst /,\,$1)
   EXEC = exe
   IN=
else
   ifeq ($(shell uname), Linux)
	  RM = rm -rf
	  FixPath = $1
	  EXEC = out
	  IN=-lm
   endif
endif

# Makefile will not run target command if the name with file already exists. To override, use .PHONY
#.PHONY : all run test coverage cppcheck valgrind clean
#all:$(BUILD_DIR)
#	gcc mainProject.c $(SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC)) $(IN)
#run: all
#	$(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
#test: $(SRC) $(TEST_SRC)
#	gcc $^ $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) $(IN)
#	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) 



	
#coverage:${PROJECT_NAME}
#	gcc -fprofile-arcs -ftest-coverage $(SRC) $(TEST_SRC) $(INC) -o $(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC)) $(IN)
#	$(call FixPath,$(BUILD_DIR)/$(TEST_PROJ_NAME).$(EXEC))
#	gcov -a $(SRC)
#	
#cppcheck: $(SRC)
#	cppcheck --enable=all main.c $(SRC)
#valgrind:
#	valgrind $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).$(EXEC))
#
#clean:
#	$(RM) $(call FixPath,$(BUILD_DIR)/*)
#	rmdir $(BUILD_DIR) 
all: $(SRC) $(BUILD)
	gcc $(SRC) $(INC) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm


run: all
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

# Build and run of Unit test

build_test:
	gcc $(TEST_SRC) $(INC) $(INCLUDE_LIBS) -o $(call FixPath,$(PROJ_NAME).$(EXEC)) -lm

run_test: build_test
	./$(call FixPath,$(PROJ_NAME).$(EXEC))

analyze: test memcheck staticcheck coverage sanitize_check

staticcheck:
	cppcheck --enable=all -iunity .

memcheck:
	valgrind ./$(TEST_OUTPUT)

sanitize_check:
	gcc -fsanitize=address -fno-omit-frame-pointer $(TEST_SRC) $(INC) -o $(TEST_OUTPUT) 
	./$(TEST_OUTPUT)

clean:
	$(RM) $(call FixPath,$(PROJ_NAME).$(EXEC))
