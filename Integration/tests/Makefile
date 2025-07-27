TEST_FILES = *.txt

.PHONY: graph clean

clean:
	@rm -rf *.txt && \
	cd graphs && \
	rm -rf *.png

graph:
	python3 graph.py $(TEST_FILES)

