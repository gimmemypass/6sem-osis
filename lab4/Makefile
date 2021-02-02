BUILD_DIR = build

app: main.cpp algo.cpp create_build_dir
		g++ main.cpp algo.cpp -o $(BUILD_DIR)/app 
.PHONY: app

create_build_dir: 
		mkdir -p $(BUILD_DIR)
.PHONY: create_build_dir

clean_project:
		rm -rf $(BUILD_DIR)
.PHONY: clean_project

test: clean_tests app
		./run_tests.sh
.PHONY: test

clean_tests:
		rm -f tests/out-[0123456789]*.txt
.PHONY: clean_tests

