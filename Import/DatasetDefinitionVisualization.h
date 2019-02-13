#ifndef DATASETDEFINITIONVISUALIZATION_H
#define DATASETDEFINITIONVISUALIZATION_H

#include <QWidget>

class DatasetDefinition;
class QTreeWidgetItem;

namespace Ui {
    class DatasetDefinitionVisualization;
}

/**
 * @brief Widget for visualization of dataset definition.
 */
class DatasetDefinitionVisualization : public QWidget
{
    Q_OBJECT
public:
    explicit DatasetDefinitionVisualization(QWidget *parent = 0);

    virtual ~DatasetDefinitionVisualization();

    void setDatasetDefiniton(DatasetDefinition* datasetDefinition);

    void clear();

    DatasetDefinition* getDatasetDefinition();

public slots:
    /**
     * Trigerred when currently selected column in coupled widget changed.
     * Used to sync widgets displaying columns.
     * @param column currently selected column.
     */
    void selectCurrentColumn(int column);

private:
    Q_DISABLE_COPY(DatasetDefinitionVisualization)

    Ui::DatasetDefinitionVisualization *ui;

    const QString typeNameString_;

    const QString typeNameFloat_;

    const QString typeNameDate_;

    DatasetDefinition* datasetDefinition_;

private slots:
    void searchTextChanged(const QString& newText);

    void currentColumnOnTreeChanged(QTreeWidgetItem* current,
                                    QTreeWidgetItem* previous);

    void on_SelectAll_clicked();

    void on_UnselectAll_clicked();

    void specialColumnChanged(int newIndex);

signals:
    /**
     * Emit signal when selected column was changed to sync widgets
     * displaying columns.
     * @param currentColumn currently selected column.
     */
    void currentColumnNeedSync(int currentColumn);
};

#endif // DATASETDEFINITIONVISUALIZATION_H