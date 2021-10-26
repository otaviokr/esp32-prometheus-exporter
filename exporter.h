/**
 * This class will gather data to expose to Prometheus.
 * Keep in mind that you need to provide the data to this class at the moment it makes sense to collect it,
 * and also arrange the web server endpoint that Prometheus will request the data.
 * This class will only collect and format the data as Prometheus expects.
 */

// <metric name>{<label name>=<label value>, ...}
// api_http_requests_total{method="POST", handler="/messages"}

#include <string>
#include "metric_type.h"
#include "metric.h"

#ifndef PROMETHEUS_EXPORTER_H
#define PROMETHEUS_EXPORTER_H

class PrometheusExporter {
    public:
    PrometheusExporter();
    void defineMetric(std::string name, std::string description, enum PrometheusMetricType type, enum PrometheusMetricValueType valueType);
    void defineMetric(std::string name, std::string description, std::string comment, enum PrometheusMetricType type, enum PrometheusMetricValueType valueType);
    void setValue(std::string name, int value);
    void setValue(std::string name, float value);
    void setValue(std::string name, double value);
    enum PrometheusMetricType getType();
    enum PrometheusMetricValueType getValueType();
    std::string toString();

    private:
    PrometheusMetric* metrics[10];
    int total;
    int current;
    int getMetricIndex(std::string metric);
};

#endif
