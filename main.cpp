#include <iostream>
#include <string>
#include "exporter.h"

int main(int argc, char const *argv[]) {
    PrometheusExporter* pe = new PrometheusExporter();

    pe->defineMetric("m1", "d1", PrometheusMetricType::Counter, PrometheusMetricValueType::Integer);
    pe->defineMetric("m2", "d2", "c2", PrometheusMetricType::Gauge, PrometheusMetricValueType::Integer);

    for(int i = 0; i < 10; i++) {
        pe->setValue("m1", i);
        pe->setValue("m2", 10 - i);
        std::cout << pe->toString();
        std::cout << "-----------\n";
    }

    return 0;
}
