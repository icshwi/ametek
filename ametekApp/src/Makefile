TOP=../..

include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE
#=============================

#=============================
# Build the IOC application

PROD_IOC = ametek
# ametek.dbd will be created and installed
DBD += ametek.dbd

# ametek.dbd will be made up from these files:
ametek_DBD += base.dbd

# Include dbd files from all support applications:
#ametek_DBD += xxx.dbd

# Add all the support libraries needed by this IOC
#ametek_LIBS += xxx

# ametek_registerRecordDeviceDriver.cpp derives from ametek.dbd
ametek_SRCS += ametek_registerRecordDeviceDriver.cpp

# Build the main IOC entry point on workstation OSs.
ametek_SRCS_DEFAULT += ametekMain.cpp
ametek_SRCS_vxWorks += -nil-

# Add support from base/src/vxWorks if needed
#ametek_OBJS_vxWorks += $(EPICS_BASE_BIN)/vxComLibrary

# Finally link to the EPICS Base libraries
ametek_LIBS += $(EPICS_BASE_IOC_LIBS)

#===========================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

