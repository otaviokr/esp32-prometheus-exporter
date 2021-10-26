#ifndef PROMETHEUS_METRIC_TYPE_H
#define PROMETHEUS_METRIC_TYPE_H

// Values can be stored as double, float or int values.
enum PrometheusMetricValueType {
    Double, Float, Integer
};

// https://prometheus.io/docs/concepts/metric_types/
enum PrometheusMetricType {
    Counter, Gauge, Histogram, Summary
};

#endif