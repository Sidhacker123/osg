// sampleProj2.cpp : Defines the initialization routines for the DLL.
//

#include "pch.h"
#include "framework.h"
#include <aced.h>
#include <dbents.h>
#include <dbapserv.h>
#include <adscodes.h>
#include <acedads.h>
#include <dbcolor.h>
#include <dbmain.h>
#include "acedCmdNF.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
static void addLinee();
static void addLin();
static void addLine()
{
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    AcDbBlockTable* pBlockTable;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    AcDbBlockTableRecord* pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE,
        pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();

    ads_point pt1, pt2;
    acedGetPoint(NULL, _T("\nSpecify 1st insertion point: "), pt1);
    AcGePoint3d startPt(pt1[0], pt1[1], pt1[2]);

    acedGetPoint(NULL, _T("\nSpecify 2nd insertion point: "), pt2);
    AcGePoint3d endPt(pt2[0], pt2[1], pt2[2]);
    AcDbLine* pLine = new AcDbLine(startPt, endPt);
    // Add the new Line object to Model space
    pBlockTableRecord->appendAcDbEntity(pLine);

    pBlockTableRecord->close();
    pLine->close();
    addLin();

}
static void addLin()
{

    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();

    AcDbBlockTable* pBlockTable;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);

    AcDbBlockTableRecord* pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE,
        pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();

    ads_point pt1, pt2;
    acedGetPoint(NULL, _T("\nSpecify 1st insertion point: "), pt1);
    AcGePoint3d startPt(pt1[0], pt1[1], pt1[2]);

    acedGetPoint(NULL, _T("\nSpecify 2nd insertion point: "), pt2);
    AcGePoint3d endPt(pt2[0], pt2[1], pt2[2]);

    AcDbLine* pLine = new AcDbLine(startPt, endPt);

    pBlockTableRecord->appendAcDbEntity(pLine);
    pBlockTableRecord->close();
    pLine->close();
    addLinee();

}

static void addLinee() {
    AcDbDatabase* pDb = acdbHostApplicationServices()->workingDatabase();
    // Open the Block Table for read-only
    AcDbBlockTable* pBlockTable;
    pDb->getSymbolTable(pBlockTable, AcDb::kForRead);
    // Get the Model Space block
    AcDbBlockTableRecord* pBlockTableRecord;
    pBlockTable->getAt(ACDB_MODEL_SPACE,
        pBlockTableRecord, AcDb::kForWrite);
    pBlockTable->close();
    // Define the points that will be used to define the Line object

    ads_point pt1, pt2;
    acedGetPoint(NULL, _T("\nSpecify 1st insertion point: "), pt1);
    AcGePoint3d startPt(pt1[0], pt1[1], pt1[2]);

    acedGetPoint(NULL, _T("\nSpecify 2nd insertion point: "), pt2);
    AcGePoint3d endPt(pt2[0], pt2[1], pt2[2]);
    // Create the new Line object in memory
    AcDbLine* pLine = new AcDbLine(startPt, endPt);
    // Add the new Line object to Model space
    pBlockTableRecord->appendAcDbEntity(pLine);
    // Close the Model space block
    pBlockTableRecord->close();
    // Close the new line object
    pLine->close();


}


extern "C" AcRx::AppRetCode acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
    switch (msg)
    {
    case AcRx::kInitAppMsg:
        acrxDynamicLinker->unlockApplication(pkt);
        acrxDynamicLinker->registerAppMDIAware(pkt);
        acutPrintf(_T("\nLoading createLine project...\n"));
        // Commands to add

        acedRegCmds->addCommand(_T("AUCommands"), _T("command"),
            _T("command"), ACRX_CMD_MODAL, addLine);//addLine  makeLayer

        break;
    case AcRx::kUnloadAppMsg:
        acutPrintf(_T("\nUnloading createLine project...\n"));
        // Command Groups to remove
        acedRegCmds->removeGroup(_T("AUCommnds"));
        break;
    default:
        break;
    }
    return AcRx::kRetOK;
}
