.PHONY: clean

PASSED := 0
FAILED:= 0
COVERAGE := 0
SHELL = /bin/bash

ready/stud-unit-test-report-prev.json: ready
	cmake .
	make unit_tests
	#echo "{\"timestamp\": \"$(shell date +"%Y-%m-%dT%H:%M:%S%:z")\", \"passed\": $(shell ./unit_tests | grep 'TESTS_PASSED' | grep -Eo '[0-9]+'), \"failed\": $(shell ./unit_tests | grep 'TESTS_FAILED' | grep -Eo '[0-9]+'), \"coverage\": $(shell gcov -o CMakeFiles/unit_tests.dir/code/ ./CMakeFiles/unit_tests.dir/code/*.o -n | grep 'algo.cpp' -A 1 | grep -Eo '([0-9]+\.[0-9]{2})')}" > report.json
	cp report.json $@

ready/stud-unit-test-report.json: ready
	cmake .
	make unit_tests
	cp report.json $@

ready/report.pdf: ready report/report.pdf
	cp report/report.pdf ready/report.pdf

ready/app-cli-debug: ready tests measures
	cmake .
	make bis22u145

report/report.pdf:
	make -C report report.pdf

ready:
	mkdir -p ready

tests:
	mkdir -p tests

measures:
	mkdir -p measures

unit_tests:
	cmake .
	make unit_tests

clean:
	make -C report clean
	rm -rf cmake-build-debug
	rm -rf CMakeFiles
	rm unit_tests
	rm lab_1
	rm -rf tests
	rm -rf measures
	rm -rf ready
	rm report.json