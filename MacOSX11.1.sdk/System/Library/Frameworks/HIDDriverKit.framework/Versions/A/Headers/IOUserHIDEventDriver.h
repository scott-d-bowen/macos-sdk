/* iig(DriverKit-107.60.3) generated from IOUserHIDEventDriver.iig */

/* IOUserHIDEventDriver.iig:1-37 */
/*
 * Copyright (c) 2018-2019 Apple Inc. All rights reserved.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_START@
 *
 * This file contains Original Code and/or Modifications of Original Code
 * as defined in and that are subject to the Apple Public Source License
 * Version 2.0 (the 'License'). You may not use this file except in
 * compliance with the License. The rights granted to you under the License
 * may not be used to create, or enable the creation or redistribution of,
 * unlawful or unlicensed copies of an Apple operating system, or to
 * circumvent, violate, or enable the circumvention or violation of, any
 * terms of an Apple operating system software license agreement.
 *
 * Please obtain a copy of the License at
 * http://www.opensource.apple.com/apsl/ and read it before using this file.
 *
 * The Original Code and all software distributed under the License are
 * distributed on an 'AS IS' basis, WITHOUT WARRANTY OF ANY KIND, EITHER
 * EXPRESS OR IMPLIED, AND APPLE HEREBY DISCLAIMS ALL SUCH WARRANTIES,
 * INCLUDING WITHOUT LIMITATION, ANY WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, QUIET ENJOYMENT OR NON-INFRINGEMENT.
 * Please see the License for the specific language governing rights and
 * limitations under the License.
 *
 * @APPLE_OSREFERENCE_LICENSE_HEADER_END@
 */

#ifndef _HIDDRIVERKIT_IOUSERHIDEVENTDRIVER_H
#define _HIDDRIVERKIT_IOUSERHIDEVENTDRIVER_H

#include <HIDDriverKit/IOUserHIDEventService.h>  /* .iig include */

class IOHIDElement;
class IOHIDEvent;
class IOHIDDigitizerCollection;

/* source class IOUserHIDEventDriver IOUserHIDEventDriver.iig:38-341 */

#if __DOCUMENTATION__
#define KERNEL IIG_KERNEL

class IOUserHIDEventDriver : public IOUserHIDEventService
{
private:
    void setAccelerationProperties() LOCALONLY;
    void setSurfaceDimensions() LOCALONLY;
    void setTipThreshold() LOCALONLY;
    
public:
    /*!
     * @function init
     *
     * @abstract
     * Initializes the object.
     *
     * @return
     * true on success.
     */
    virtual bool init() override;
    
    /*!
     * @function free
     *
     * @abstract
     * frees the object.
     */
    virtual void free() override;
    
    /*!
     * @function Start
     *
     * @abstract
     * Function called after initialization to start the IOService.
     *
     * @param provider
     * The IOService that is provider for this object.
     *
     * @return
     * returns kIOReturnSucess on sucess.
     */
    virtual kern_return_t Start(IOService *provider) override;
    
protected:
    /*!
     * @function handleReport
     *
     * @abstract
     * Callback invoked when an input report is received from the device.
     *
     * @param timestamp
     * The timestamp of the report.
     *
     * @param report
     * Bytes that describe the report.
     *
     * @param reportLength
     * The length of the report.
     *
     * @param type
     * The report type.
     *
     * @param reportID
     * The report ID.
     */
    virtual void handleReport(uint64_t              timestamp,
                              uint8_t               *report,
                              uint32_t              reportLength,
                              IOHIDReportType       type,
                              uint32_t              reportID) override LOCALONLY;
    
    /*!
     * @function parseElements
     *
     * @abstract
     * Parses the elements returned from IOHIDInterface::getElements() function.
     * This function will search for supported elements and bucketize them
     * according to their usage pages/usages.
     *
     * @param elements
     * An array of supported elements to be parsed.
     *
     * @return
     * Returns true on success.
     */
    virtual bool parseElements(OSArray *elements) LOCALONLY;
    
    /*!
     * @function parseKeyboardElement
     *
     * @abstract
     * Parses an element to see if it supports keyboard usages.
     *
     * @param element
     * An IOHIDElement object to parse.
     *
     * @return
     * Returns true on success.
     */
    virtual bool parseKeyboardElement(IOHIDElement *element) LOCALONLY;
    
    /*!
     * @function parsePointerElement
     *
     * @abstract
     * Parses an element to see if it supports pointer usages.
     *
     * @param element
     * An IOHIDElement object to parse.
     *
     * @return
     * Returns true on success.
     */
    virtual bool parsePointerElement(IOHIDElement *element) LOCALONLY;
    
    /*!
     * @function parseScrollElement
     *
     * @abstract
     * Parses an element to see if it supports scroll usages.
     *
     * @param element
     * An IOHIDElement object to parse.
     *
     * @return
     * Returns true on success.
     */
    virtual bool parseScrollElement(IOHIDElement *element) LOCALONLY;
    
    /*!
     * @function parseLEDElement
     *
     * @abstract
     * Parses an element to see if it supports LED usages.
     *
     * @param element
     * An IOHIDElement object to parse.
     *
     * @return
     * Returns true on success.
     */
    virtual bool parseLEDElement(IOHIDElement *element) LOCALONLY;
    
    /*!
     * @function parseDigitizerElement
     *
     * @abstract
     * Parses an element to see if it supports digitizer usages.
     *
     * @param element
     * An IOHIDElement object to parse.
     *
     * @return
     * Returns true on success.
     */
    virtual bool parseDigitizerElement(IOHIDElement *element) LOCALONLY;

    /*!
     * @function parseProximityElement
     *
     * @abstract
     * Parses an element to see if it supports proximity usages.
     *
     * @param element
     * An IOHIDElement object to parse.
     *
     * @return
     * Returns true on success.
     */
    virtual bool parseProximityElement(IOHIDElement *element) LOCALONLY;
    
    /*!
     * @function handleKeyboardReport
     *
     * @abstract
     * Function called after receiving an input report from the device. Iterates
     * through keyboard elements and dispatches keyboard events if the element
     * value has been updated.
     *
     * @param timestamp
     * The timestamp of the input report.
     *
     * @param reportID
     * The report ID.
     */
    virtual void handleKeyboardReport(uint64_t timestamp, uint32_t reportID) LOCALONLY;
    
    /*!
     * @function handleRelativePointerReport
     *
     * @abstract
     * Function called after receiving an input report from the device. Iterates
     * through relative pointer elements and dispatches relative pointer events
     * if the element value has been updated.
     *
     * @param timestamp
     * The timestamp of the input report.
     *
     * @param reportID
     * The report ID.
     */
    virtual void handleRelativePointerReport(uint64_t timestamp, uint32_t reportID) LOCALONLY;
    
    /*!
     * @function handleAbsolutePointerReport
     *
     * @abstract
     * Function called after receiving an input report from the device. Iterates
     * through absolute pointer elements and dispatches absolute pointer events
     * if the element value has been updated.
     *
     * @param timestamp
     * The timestamp of the input report.
     *
     * @param reportID
     * The report ID.
     */
    virtual void handleAbsolutePointerReport(uint64_t timestamp, uint32_t reportID) LOCALONLY;
    
    /*!
     * @function handleScrollReport
     *
     * @abstract
     * Function called after receiving an input report from the device. Iterates
     * through scroll elements and dispatches scroll events if the element
     * value has been updated.
     *
     * @param timestamp
     * The timestamp of the input report.
     *
     * @param reportID
     * The report ID.
     */
    virtual void handleScrollReport(uint64_t timestamp, uint32_t reportID) LOCALONLY;
    
    /*!
     * @function handleDigitizerReport
     *
     * @abstract
     * Function called after receiving an input report from the device. Iterates
     * through digitizer elements and dispatches digitizer events if the element
     * value has been updated.
     *
     * @param timestamp
     * The timestamp of the input report.
     *
     * @param reportID
     * The report ID.
     */
    virtual void handleDigitizerReport(uint64_t timestamp, uint32_t reportID) LOCALONLY;

    /*!
     * @function handleProximityReport
     *
     * @abstract
     * Function called after receiving an input report from the device. Iterates
     * through proximity elements and dispatches proximity events if the element
     * value has been updated.
     *
     * @param timestamp
     * The timestamp of the input report.
     *
     * @param reportID
     * The report ID.
     */
    virtual void handleProximityReport(uint64_t timestamp, uint32_t reportID) LOCALONLY;
    
    /*!
     * @function createEventForDigitizerCollection
     *
     * @abstract
     * Creates an IOHIDEvent representation of a digitizer collection. Called
     * on an input report for a digitizer service for dispatching digitizer
     * events. The collection will be updated with the new values from the
     * report in this call.
     *
     * @param collection
     * A digitizer collection object to create an event off of.
     *
     * @param timestamp
     * The timestamp of the input report.
     *
     * @param reportID
     * The report ID.
     *
     * @return
     * Returns a digitizer event with the proper fields set on success.
     */
    IOHIDEvent *createEventForDigitizerCollection(IOHIDDigitizerCollection *collection,
                                                  uint64_t timestamp,
                                                  uint32_t reportID) LOCALONLY;
    
    /*!
     * @function SetLED
     *
     * @abstract
     * Sets an LED on the service.
     *
     * @param usage
     * The LED usage to set. LED usages can be found in
     * <IOKit/hid/IOHIDUsageTables.h>.
     *
     * @param on
     * Turn on or off the LED.
     */
    virtual void SetLED(uint32_t usage, bool on) override;
};

#undef KERNEL
#else /* __DOCUMENTATION__ */

/* generated class IOUserHIDEventDriver IOUserHIDEventDriver.iig:38-341 */


#define IOUserHIDEventDriver_Start_Args \
        IOService * provider

#define IOUserHIDEventDriver_SetLED_Args \
        uint32_t usage, \
        bool on

#define IOUserHIDEventDriver_Methods \
\
public:\
\
    virtual kern_return_t\
    Dispatch(const IORPC rpc) APPLE_KEXT_OVERRIDE;\
\
    static kern_return_t\
    _Dispatch(IOUserHIDEventDriver * self, const IORPC rpc);\
\
    void\
    setAccelerationProperties(\
);\
\
    void\
    setSurfaceDimensions(\
);\
\
    void\
    setTipThreshold(\
);\
\
    IOHIDEvent *\
    createEventForDigitizerCollection(\
        IOHIDDigitizerCollection * collection,\
        uint64_t timestamp,\
        uint32_t reportID);\
\
\
protected:\
    /* _Impl methods */\
\
    kern_return_t\
    Start_Impl(IOService_Start_Args);\
\
    void\
    SetLED_Impl(IOHIDEventService_SetLED_Args);\
\
\
public:\
    /* _Invoke methods */\
\


#define IOUserHIDEventDriver_KernelMethods \
\
protected:\
    /* _Impl methods */\
\


#define IOUserHIDEventDriver_VirtualMethods \
\
public:\
\
    virtual bool\
    init(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    free(\
) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleReport(\
        uint64_t timestamp,\
        uint8_t * report,\
        uint32_t reportLength,\
        IOHIDReportType type,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseElements(\
        OSArray * elements) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseKeyboardElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parsePointerElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseScrollElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseLEDElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseDigitizerElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual bool\
    parseProximityElement(\
        IOHIDElement * element) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleKeyboardReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleRelativePointerReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleAbsolutePointerReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleScrollReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleDigitizerReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\
    virtual void\
    handleProximityReport(\
        uint64_t timestamp,\
        uint32_t reportID) APPLE_KEXT_OVERRIDE;\
\


#if !KERNEL

extern OSMetaClass          * gIOUserHIDEventDriverMetaClass;
extern const OSClassLoadInformation IOUserHIDEventDriver_Class;

class IOUserHIDEventDriverMetaClass : public OSMetaClass
{
public:
    virtual kern_return_t
    New(OSObject * instance) override;
    virtual kern_return_t
    Dispatch(const IORPC rpc) override;
};

#endif /* !KERNEL */

#if !KERNEL

class IOUserHIDEventDriverInterface : public OSInterface
{
public:
    virtual bool
    parseElements(OSArray * elements) = 0;

    virtual bool
    parseKeyboardElement(IOHIDElement * element) = 0;

    virtual bool
    parsePointerElement(IOHIDElement * element) = 0;

    virtual bool
    parseScrollElement(IOHIDElement * element) = 0;

    virtual bool
    parseLEDElement(IOHIDElement * element) = 0;

    virtual bool
    parseDigitizerElement(IOHIDElement * element) = 0;

    virtual bool
    parseProximityElement(IOHIDElement * element) = 0;

    virtual void
    handleKeyboardReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleRelativePointerReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleAbsolutePointerReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleScrollReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleDigitizerReport(uint64_t timestamp,
        uint32_t reportID) = 0;

    virtual void
    handleProximityReport(uint64_t timestamp,
        uint32_t reportID) = 0;

};

struct IOUserHIDEventDriver_IVars;
struct IOUserHIDEventDriver_LocalIVars;

class IOUserHIDEventDriver : public IOUserHIDEventService, public IOUserHIDEventDriverInterface
{
#if !KERNEL
    friend class IOUserHIDEventDriverMetaClass;
#endif /* !KERNEL */

#if !KERNEL
public:
    union
    {
        IOUserHIDEventDriver_IVars * ivars;
        IOUserHIDEventDriver_LocalIVars * lvars;
    };
#endif /* !KERNEL */

    using super = IOUserHIDEventService;

#if !KERNEL
    IOUserHIDEventDriver_Methods
    IOUserHIDEventDriver_VirtualMethods
#endif /* !KERNEL */

};
#endif /* !KERNEL */


#endif /* !__DOCUMENTATION__ */

/* IOUserHIDEventDriver.iig:343- */

#endif /* _HIDDRIVERKIT_IOUSERHIDEVENTDRIVER_H */
