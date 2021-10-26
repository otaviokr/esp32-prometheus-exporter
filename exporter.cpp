
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include "exporter.h"


PrometheusExporter::PrometheusExporter() {
    this->total = 10;
    this->current = 0;
}

void PrometheusExporter::defineMetric(std::string name, std::string description,
        enum PrometheusMetricType type, enum PrometheusMetricValueType valueType) {
    this->defineMetric(name, description, "", type, valueType);
}

void PrometheusExporter::defineMetric(std::string name, std::string description, std::string comment,
        enum PrometheusMetricType type, enum PrometheusMetricValueType valueType) {
    if (this->current < this->total) {
        this->metrics[this->current] = new PrometheusMetric(name, description, comment, type, valueType);
    } else {
        this->metrics[this->total - 1] = new PrometheusMetric("OVERFLOW", "METRIC OVERFLOW ERROR", "YOU HAVE TOO MANY METRICS TO MONITOR! CHECK YOUR CODE!", type, valueType);
    }
    this->current++;
}

void PrometheusExporter::setValue(std::string name, int value) {
    int index = this->getMetricIndex(name);
    if (index > -1) {
        this->metrics[index]->setValue(value);
    } else {
        this->defineMetric(name, "", PrometheusMetricType::Gauge, PrometheusMetricValueType::Integer);
    }
}

void PrometheusExporter::setValue(std::string name, float value) {
    int index = this->getMetricIndex(name);
    if (index > -1) {
        this->metrics[index]->setValue(value);
    } else {
        this->defineMetric(name, "", PrometheusMetricType::Gauge, PrometheusMetricValueType::Float);
    }
}

void PrometheusExporter::setValue(std::string name, double value) {
    int index = this->getMetricIndex(name);
    if (index > -1) {
        this->metrics[index]->setValue(value);
    } else {
        this->defineMetric(name, "", PrometheusMetricType::Gauge, PrometheusMetricValueType::Double);
    }
}

std::string PrometheusExporter::toString() {
    std::string output = "";
    for (int i = 0; i < this->current; i++) {
        std::string description = this->metrics[i]->getDescription();
        if (sizeof(description) > 0) {
            output += "# HELP " + description + "\n";
        }
        output += "# TYPE " + this->metrics[i]->getName() + " " + this->metrics[i]->getType() + "\n";
        std::string comment = this->metrics[i]->getComment();
        if (comment.size() > 0) {
            output += "# " + comment + "\n";
        }
        output += this->metrics[i]->getName() + " " + this->metrics[i]->getValueAsString();

        if (i < this->current - 1) {
            output += "\n";
        }
    }
    return output;
}

int PrometheusExporter::getMetricIndex(std::string metric) {
    for(int i = 0; i < this->total; i++) {
        if(metric.compare(this->metrics[i]->getName()) == 0) {
            return i;
        }
    }
    return -1;
}
