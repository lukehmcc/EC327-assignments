.PHONY: run clean

run:
	@mkdir -p build && \
	cd build && \
	cmake .. -DCMAKE_BUILD_TYPE=Release && \
	cmake --build . --target run

clean:
	rm -rf build
