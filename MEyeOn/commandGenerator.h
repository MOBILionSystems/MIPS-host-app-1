#ifndef COMMANDGENERATOR_H
#define COMMANDGENERATOR_H

#include <QObject>
#include <QJsonObject>
#include <QUuid>
#include "common.h"

class CommandGenerator : public QObject
{
    Q_OBJECT
public:
    explicit CommandGenerator(QObject *parent = nullptr);
    QJsonObject getCommand(CommandType type, QString fileName = "");
    static QString getUUID();
    QString currentTalismanUUID() const;
    unsigned int lastUsedSequency() const;

signals:

private:
    QString talismanUUID;
    unsigned int sequence = 1;
    void initCommand(QJsonObject& command);
    void updateInitDigtizerCommand(QJsonObject& command);
    void updateStartAcqCommand(QJsonObject& command, QString fileName);
    void updateStopAcqCommand(QJsonObject& command);
};

#endif // COMMANDGENERATOR_H
