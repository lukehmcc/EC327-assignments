.PHONY: run clean

run:
	@mkdir -p build && \
	cd build && \
	cmake .. -DCMAKE_BUILD_TYPE=Release && \
	cmake --build . --target run

test:
	@mkdir -p build && \
	cd build && \
	cmake .. -DCMAKE_BUILD_TYPE=Release && \
	cmake --build . --target test

clean:
	rm -rf build
