#include <stack>

void hanoi_none_recursive(int n, char from, char to, char via) {
    struct Element {
	int n; char from; char to; char via;
    };

    std::stack<Element> elements;
    elements.push({n, from, to, via});

    while (!elements.empty()) {
	auto element = elements.top();
	elements.pop();
	n = element.n;
	from = element.from;
	to = element.to;
	via = element.via;

	if (n==1) {
	    printf("%c -> %c\n", from, to);
	} else {
	    //todo:
	    elements.push({n-1, via, to, from});
	    elements.push({1, from, to, via});
	    elements.push({n-1, from, via, to});
	}
    }
}
