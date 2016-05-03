#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDebug"
#include "QDomComment"

void MainWindow::addNode_INTUIT(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement,sampleElement,projectsElement,projectElement;
    sampleElement = domDoc.documentElement().firstChild().toElement();
    domElement = domDoc.createElement("projects");
    sampleElement.appendChild( domElement );

    projectsElement =sampleElement.firstChild().toElement();
    domElement = domDoc.createElement("project");
    projectsElement.appendChild( domElement );

   // qDebug()<<projectsElement.firstChild().toElement().tagName();
    domElement.setAttribute("sampleNo","JLXC-160425-1");                      //条形码
    domElement.setAttribute("projectName",QString::fromUtf8("起动试验"));      //项目名字
    domElement.setAttribute("testResult","1");

    projectElement =projectsElement.firstChild().toElement();
    domElement = domDoc.createElement("testData");
    projectElement.appendChild( domElement );//检定结果

    domElement.setAttribute("testPhase","0");
    domElement.setAttribute("testGroup","L");
    domElement.setAttribute("freq","50Hz");
    domElement.setAttribute("PF","1.0");
    domElement.setAttribute("volt","Un");

    domElement.setAttribute("curr","0.004Ib");
    domElement.setAttribute("conclusion","0");
    domElement.setAttribute("refTime",QString::fromUtf8("10分13秒"));
    domElement.setAttribute("strSampleID","160311025630");

}

bool MainWindow::addNode_sample(QString nodeName, QDomDocument &domDoc)
{
    QDomElement  domElement;
    domElement = domDoc.createElement( nodeName );
    domDoc.documentElement().appendChild( domElement );
     //qDebug()<<domDoc.toString();
#if 1
    domElement.setAttribute("sampleNo","equipmentname");
    domElement.setAttribute("checkResult","CSC101B");
    domElement.setAttribute("checkDate","itemName");
    domElement.setAttribute("testMan","equipmentname");
    domElement.setAttribute("checkMan","CSC101B");

    domElement.setAttribute("checkTemp","equipmentname");
    domElement.setAttribute("checkWet","CSC101B");
    domElement.setAttribute("checkVolt","itemName");
    domElement.setAttribute("checkCurr","equipmentname");
    domElement.setAttribute("checkRate","CSC101B");

    domElement.setAttribute("checkClass","equipmentname");
    domElement.setAttribute("factory","CSC101B");
    domElement.setAttribute("metConst","itemName");
    domElement.setAttribute("metVarConst","equipmentname");
    domElement.setAttribute("metClass","CSC101B");

    domElement.setAttribute("metVarClass","equipmentname");
    domElement.setAttribute("metPhase","CSC101B");

#endif
    return true;
}

