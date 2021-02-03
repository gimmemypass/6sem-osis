BUILD_DIR = build

app: main.cpp calc.cpp create_build_dir
		g++ -pthread -std=c++20 -lstdc++fs main.cpp calc.cpp -o $(BUILD_DIR)/app 
.PHONY: app

create_build_dir: 
		mkdir -p $(BUILD_DIR)
.PHONY: create_build_dir

clean_project: clean_tests
		rm -rf $(BUILD_DIR)
.PHONY: clean_project

test: clean_tests app
		$(BUILD_DIR)/app tests out.txt
.PHONY: test

clean_tests:
		rm -f out.txt
.PHONY: clean_tests
