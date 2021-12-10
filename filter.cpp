#include "filter.hpp"



class FilterMedian: FilterInterface {
public:
    std::list<double> window;
    int size = 10;

    void Load(cJSON* json) {
        this->size = json_get_int(json, "size");
    }

    double Push(double value) {
        window.push_back(value);
        if (window.size() > size) window.pop_front();
        auto sum = std::accumulate(window.begin(), window.end(), 0);
        return sum / window.size();
    }
};




Filter::Filter(): filter(nullptr)
{
}

Filter::~Filter()
{
	if (filter)
		delete filter;
}

void Filter::Load(cJSON* json) {
    std::string alg = json_get_string(json, "type");
    //TODO 创建算法实例
    if (alg == "median") {
        filter = (FilterInterface*)new FilterMedian();
    }

    if (filter)
        filter->Load(json_get(json, "options"));
}

double Filter::Push(double value) {
    if (filter)
        return filter->Push(value);
    return value;
}
