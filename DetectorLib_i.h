

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Nov 22 22:41:29 2013
 */
/* Compiler settings for DetectorLib.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __DetectorLib_i_h__
#define __DetectorLib_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISocketChannel_FWD_DEFINED__
#define __ISocketChannel_FWD_DEFINED__
typedef interface ISocketChannel ISocketChannel;
#endif 	/* __ISocketChannel_FWD_DEFINED__ */


#ifndef __IEngine_FWD_DEFINED__
#define __IEngine_FWD_DEFINED__
typedef interface IEngine IEngine;
#endif 	/* __IEngine_FWD_DEFINED__ */


#ifndef __ICmdCoderDT_FWD_DEFINED__
#define __ICmdCoderDT_FWD_DEFINED__
typedef interface ICmdCoderDT ICmdCoderDT;
#endif 	/* __ICmdCoderDT_FWD_DEFINED__ */


#ifndef __ICmdController_FWD_DEFINED__
#define __ICmdController_FWD_DEFINED__
typedef interface ICmdController ICmdController;
#endif 	/* __ICmdController_FWD_DEFINED__ */


#ifndef __IImgController_FWD_DEFINED__
#define __IImgController_FWD_DEFINED__
typedef interface IImgController IImgController;
#endif 	/* __IImgController_FWD_DEFINED__ */


#ifndef __IImgCoder_FWD_DEFINED__
#define __IImgCoder_FWD_DEFINED__
typedef interface IImgCoder IImgCoder;
#endif 	/* __IImgCoder_FWD_DEFINED__ */


#ifndef __IImgDisplay_FWD_DEFINED__
#define __IImgDisplay_FWD_DEFINED__
typedef interface IImgDisplay IImgDisplay;
#endif 	/* __IImgDisplay_FWD_DEFINED__ */


#ifndef __IImgObject_FWD_DEFINED__
#define __IImgObject_FWD_DEFINED__
typedef interface IImgObject IImgObject;
#endif 	/* __IImgObject_FWD_DEFINED__ */


#ifndef ___ISocketChannelEvents_FWD_DEFINED__
#define ___ISocketChannelEvents_FWD_DEFINED__
typedef interface _ISocketChannelEvents _ISocketChannelEvents;
#endif 	/* ___ISocketChannelEvents_FWD_DEFINED__ */


#ifndef __SocketChannel_FWD_DEFINED__
#define __SocketChannel_FWD_DEFINED__

#ifdef __cplusplus
typedef class SocketChannel SocketChannel;
#else
typedef struct SocketChannel SocketChannel;
#endif /* __cplusplus */

#endif 	/* __SocketChannel_FWD_DEFINED__ */


#ifndef ___IEngineEvents_FWD_DEFINED__
#define ___IEngineEvents_FWD_DEFINED__
typedef interface _IEngineEvents _IEngineEvents;
#endif 	/* ___IEngineEvents_FWD_DEFINED__ */


#ifndef __Engine_FWD_DEFINED__
#define __Engine_FWD_DEFINED__

#ifdef __cplusplus
typedef class Engine Engine;
#else
typedef struct Engine Engine;
#endif /* __cplusplus */

#endif 	/* __Engine_FWD_DEFINED__ */


#ifndef ___ICmdCoderDTEvents_FWD_DEFINED__
#define ___ICmdCoderDTEvents_FWD_DEFINED__
typedef interface _ICmdCoderDTEvents _ICmdCoderDTEvents;
#endif 	/* ___ICmdCoderDTEvents_FWD_DEFINED__ */


#ifndef __CmdCoderDT_FWD_DEFINED__
#define __CmdCoderDT_FWD_DEFINED__

#ifdef __cplusplus
typedef class CmdCoderDT CmdCoderDT;
#else
typedef struct CmdCoderDT CmdCoderDT;
#endif /* __cplusplus */

#endif 	/* __CmdCoderDT_FWD_DEFINED__ */


#ifndef __CmdController_FWD_DEFINED__
#define __CmdController_FWD_DEFINED__

#ifdef __cplusplus
typedef class CmdController CmdController;
#else
typedef struct CmdController CmdController;
#endif /* __cplusplus */

#endif 	/* __CmdController_FWD_DEFINED__ */


#ifndef ___IImgControllerEvents_FWD_DEFINED__
#define ___IImgControllerEvents_FWD_DEFINED__
typedef interface _IImgControllerEvents _IImgControllerEvents;
#endif 	/* ___IImgControllerEvents_FWD_DEFINED__ */


#ifndef __ImgController_FWD_DEFINED__
#define __ImgController_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImgController ImgController;
#else
typedef struct ImgController ImgController;
#endif /* __cplusplus */

#endif 	/* __ImgController_FWD_DEFINED__ */


#ifndef __ImgCoder_FWD_DEFINED__
#define __ImgCoder_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImgCoder ImgCoder;
#else
typedef struct ImgCoder ImgCoder;
#endif /* __cplusplus */

#endif 	/* __ImgCoder_FWD_DEFINED__ */


#ifndef ___IImgDisplayEvents_FWD_DEFINED__
#define ___IImgDisplayEvents_FWD_DEFINED__
typedef interface _IImgDisplayEvents _IImgDisplayEvents;
#endif 	/* ___IImgDisplayEvents_FWD_DEFINED__ */


#ifndef __ImgDisplay_FWD_DEFINED__
#define __ImgDisplay_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImgDisplay ImgDisplay;
#else
typedef struct ImgDisplay ImgDisplay;
#endif /* __cplusplus */

#endif 	/* __ImgDisplay_FWD_DEFINED__ */


#ifndef ___IImgObjectEvents_FWD_DEFINED__
#define ___IImgObjectEvents_FWD_DEFINED__
typedef interface _IImgObjectEvents _IImgObjectEvents;
#endif 	/* ___IImgObjectEvents_FWD_DEFINED__ */


#ifndef __ImgObject_FWD_DEFINED__
#define __ImgObject_FWD_DEFINED__

#ifdef __cplusplus
typedef class ImgObject ImgObject;
#else
typedef struct ImgObject ImgObject;
#endif /* __cplusplus */

#endif 	/* __ImgObject_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ISocketChannel_INTERFACE_DEFINED__
#define __ISocketChannel_INTERFACE_DEFINED__

/* interface ISocketChannel */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ISocketChannel;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("41F30060-F1C4-4526-BBD4-389213097634")
    ISocketChannel : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RemoteIP( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RemoteIP( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_RemotePort( 
            /* [retval][out] */ SHORT *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_RemotePort( 
            /* [in] */ SHORT newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Open( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectHandle( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISocketChannelVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISocketChannel * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISocketChannel * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISocketChannel * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ISocketChannel * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ISocketChannel * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ISocketChannel * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ISocketChannel * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteIP )( 
            ISocketChannel * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteIP )( 
            ISocketChannel * This,
            /* [in] */ BSTR newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RemotePort )( 
            ISocketChannel * This,
            /* [retval][out] */ SHORT *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RemotePort )( 
            ISocketChannel * This,
            /* [in] */ SHORT newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            ISocketChannel * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            ISocketChannel * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectHandle )( 
            ISocketChannel * This,
            /* [retval][out] */ ULONG *pVal);
        
        END_INTERFACE
    } ISocketChannelVtbl;

    interface ISocketChannel
    {
        CONST_VTBL struct ISocketChannelVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISocketChannel_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ISocketChannel_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ISocketChannel_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ISocketChannel_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ISocketChannel_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ISocketChannel_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ISocketChannel_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ISocketChannel_get_RemoteIP(This,pVal)	\
    ( (This)->lpVtbl -> get_RemoteIP(This,pVal) ) 

#define ISocketChannel_put_RemoteIP(This,newVal)	\
    ( (This)->lpVtbl -> put_RemoteIP(This,newVal) ) 

#define ISocketChannel_get_RemotePort(This,pVal)	\
    ( (This)->lpVtbl -> get_RemotePort(This,pVal) ) 

#define ISocketChannel_put_RemotePort(This,newVal)	\
    ( (This)->lpVtbl -> put_RemotePort(This,newVal) ) 

#define ISocketChannel_Open(This)	\
    ( (This)->lpVtbl -> Open(This) ) 

#define ISocketChannel_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define ISocketChannel_get_ObjectHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_ObjectHandle(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ISocketChannel_INTERFACE_DEFINED__ */


#ifndef __IEngine_INTERFACE_DEFINED__
#define __IEngine_INTERFACE_DEFINED__

/* interface IEngine */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("51B14E26-E6CC-473A-82EB-6401661F5300")
    IEngine : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ChannelHandle( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ChannelHandle( 
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ObjectHandle( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEngine * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEngine * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEngine * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEngine * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEngine * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Start )( 
            IEngine * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IEngine * This);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ChannelHandle )( 
            IEngine * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ChannelHandle )( 
            IEngine * This,
            /* [in] */ ULONG newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ObjectHandle )( 
            IEngine * This,
            /* [retval][out] */ ULONG *pVal);
        
        END_INTERFACE
    } IEngineVtbl;

    interface IEngine
    {
        CONST_VTBL struct IEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEngine_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEngine_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEngine_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEngine_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IEngine_Start(This)	\
    ( (This)->lpVtbl -> Start(This) ) 

#define IEngine_Stop(This)	\
    ( (This)->lpVtbl -> Stop(This) ) 

#define IEngine_get_ChannelHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_ChannelHandle(This,pVal) ) 

#define IEngine_put_ChannelHandle(This,newVal)	\
    ( (This)->lpVtbl -> put_ChannelHandle(This,newVal) ) 

#define IEngine_get_ObjectHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_ObjectHandle(This,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEngine_INTERFACE_DEFINED__ */


#ifndef __ICmdCoderDT_INTERFACE_DEFINED__
#define __ICmdCoderDT_INTERFACE_DEFINED__

/* interface ICmdCoderDT */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICmdCoderDT;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("604C6AA2-858A-437A-A65A-249894D90B3B")
    ICmdCoderDT : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICmdCoderDTVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICmdCoderDT * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICmdCoderDT * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICmdCoderDT * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICmdCoderDT * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICmdCoderDT * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICmdCoderDT * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICmdCoderDT * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ICmdCoderDTVtbl;

    interface ICmdCoderDT
    {
        CONST_VTBL struct ICmdCoderDTVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICmdCoderDT_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICmdCoderDT_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICmdCoderDT_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICmdCoderDT_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICmdCoderDT_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICmdCoderDT_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICmdCoderDT_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICmdCoderDT_INTERFACE_DEFINED__ */


#ifndef __ICmdController_INTERFACE_DEFINED__
#define __ICmdController_INTERFACE_DEFINED__

/* interface ICmdController */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_ICmdController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("47FEC6A5-CD9A-4112-875E-44E0BA587EF3")
    ICmdController : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct ICmdControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICmdController * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICmdController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICmdController * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICmdController * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICmdController * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICmdController * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICmdController * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } ICmdControllerVtbl;

    interface ICmdController
    {
        CONST_VTBL struct ICmdControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICmdController_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICmdController_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICmdController_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICmdController_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICmdController_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICmdController_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICmdController_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICmdController_INTERFACE_DEFINED__ */


#ifndef __IImgController_INTERFACE_DEFINED__
#define __IImgController_INTERFACE_DEFINED__

/* interface IImgController */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImgController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6BFD301F-AA15-4295-BF88-AA7657F10C94")
    IImgController : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IImgControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImgController * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImgController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImgController * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImgController * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImgController * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImgController * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImgController * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IImgControllerVtbl;

    interface IImgController
    {
        CONST_VTBL struct IImgControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImgController_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImgController_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImgController_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImgController_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImgController_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImgController_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImgController_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImgController_INTERFACE_DEFINED__ */


#ifndef __IImgCoder_INTERFACE_DEFINED__
#define __IImgCoder_INTERFACE_DEFINED__

/* interface IImgCoder */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImgCoder;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17C49305-148A-4DFF-A8A4-E63D7DB1746F")
    IImgCoder : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IImgCoderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImgCoder * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImgCoder * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImgCoder * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImgCoder * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImgCoder * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImgCoder * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImgCoder * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IImgCoderVtbl;

    interface IImgCoder
    {
        CONST_VTBL struct IImgCoderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImgCoder_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImgCoder_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImgCoder_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImgCoder_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImgCoder_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImgCoder_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImgCoder_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImgCoder_INTERFACE_DEFINED__ */


#ifndef __IImgDisplay_INTERFACE_DEFINED__
#define __IImgDisplay_INTERFACE_DEFINED__

/* interface IImgDisplay */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImgDisplay;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3A62B931-C8B7-44A3-A148-6FB1254C6080")
    IImgDisplay : public IDispatch
    {
    public:
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_AutoSize( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_AutoSize( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_DrawMode( 
            /* [in] */ long mode) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_DrawMode( 
            /* [retval][out] */ long *pmode) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_HWND( 
            /* [retval][out] */ LONG_PTR *pHWND) = 0;
        
        virtual /* [id][requestedit][bindable][propput] */ HRESULT STDMETHODCALLTYPE put_BorderVisible( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][requestedit][bindable][propget] */ HRESULT STDMETHODCALLTYPE get_BorderVisible( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Open( 
            /* [in] */ ULONG width,
            /* [in] */ ULONG height) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ImgHandle( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ImgHandle( 
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MapStart( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MapStart( 
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MapEnd( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MapEnd( 
            /* [in] */ ULONG newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImgDisplayVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImgDisplay * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImgDisplay * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImgDisplay * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImgDisplay * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImgDisplay * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImgDisplay * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImgDisplay * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AutoSize )( 
            IImgDisplay * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AutoSize )( 
            IImgDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DrawMode )( 
            IImgDisplay * This,
            /* [in] */ long mode);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DrawMode )( 
            IImgDisplay * This,
            /* [retval][out] */ long *pmode);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HWND )( 
            IImgDisplay * This,
            /* [retval][out] */ LONG_PTR *pHWND);
        
        /* [id][requestedit][bindable][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BorderVisible )( 
            IImgDisplay * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][requestedit][bindable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BorderVisible )( 
            IImgDisplay * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Open )( 
            IImgDisplay * This,
            /* [in] */ ULONG width,
            /* [in] */ ULONG height);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Close )( 
            IImgDisplay * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImgHandle )( 
            IImgDisplay * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ImgHandle )( 
            IImgDisplay * This,
            /* [in] */ ULONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MapStart )( 
            IImgDisplay * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MapStart )( 
            IImgDisplay * This,
            /* [in] */ ULONG newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MapEnd )( 
            IImgDisplay * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MapEnd )( 
            IImgDisplay * This,
            /* [in] */ ULONG newVal);
        
        END_INTERFACE
    } IImgDisplayVtbl;

    interface IImgDisplay
    {
        CONST_VTBL struct IImgDisplayVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImgDisplay_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImgDisplay_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImgDisplay_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImgDisplay_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImgDisplay_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImgDisplay_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImgDisplay_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IImgDisplay_put_AutoSize(This,vbool)	\
    ( (This)->lpVtbl -> put_AutoSize(This,vbool) ) 

#define IImgDisplay_get_AutoSize(This,pbool)	\
    ( (This)->lpVtbl -> get_AutoSize(This,pbool) ) 

#define IImgDisplay_put_DrawMode(This,mode)	\
    ( (This)->lpVtbl -> put_DrawMode(This,mode) ) 

#define IImgDisplay_get_DrawMode(This,pmode)	\
    ( (This)->lpVtbl -> get_DrawMode(This,pmode) ) 

#define IImgDisplay_get_HWND(This,pHWND)	\
    ( (This)->lpVtbl -> get_HWND(This,pHWND) ) 

#define IImgDisplay_put_BorderVisible(This,vbool)	\
    ( (This)->lpVtbl -> put_BorderVisible(This,vbool) ) 

#define IImgDisplay_get_BorderVisible(This,pbool)	\
    ( (This)->lpVtbl -> get_BorderVisible(This,pbool) ) 

#define IImgDisplay_Open(This,width,height)	\
    ( (This)->lpVtbl -> Open(This,width,height) ) 

#define IImgDisplay_Close(This)	\
    ( (This)->lpVtbl -> Close(This) ) 

#define IImgDisplay_get_ImgHandle(This,pVal)	\
    ( (This)->lpVtbl -> get_ImgHandle(This,pVal) ) 

#define IImgDisplay_put_ImgHandle(This,newVal)	\
    ( (This)->lpVtbl -> put_ImgHandle(This,newVal) ) 

#define IImgDisplay_get_MapStart(This,pVal)	\
    ( (This)->lpVtbl -> get_MapStart(This,pVal) ) 

#define IImgDisplay_put_MapStart(This,newVal)	\
    ( (This)->lpVtbl -> put_MapStart(This,newVal) ) 

#define IImgDisplay_get_MapEnd(This,pVal)	\
    ( (This)->lpVtbl -> get_MapEnd(This,pVal) ) 

#define IImgDisplay_put_MapEnd(This,newVal)	\
    ( (This)->lpVtbl -> put_MapEnd(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImgDisplay_INTERFACE_DEFINED__ */


#ifndef __IImgObject_INTERFACE_DEFINED__
#define __IImgObject_INTERFACE_DEFINED__

/* interface IImgObject */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IImgObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E5CBD205-BBD6-4EAD-9943-6DAE0C27F6AA")
    IImgObject : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Width( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Height( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Deepth( 
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Pixel( 
            /* [in] */ ULONG x,
            /* [in] */ ULONG y,
            /* [retval][out] */ ULONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Pixel( 
            /* [in] */ ULONG x,
            /* [in] */ ULONG y,
            /* [in] */ ULONG newVal) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ImageLineAddress( 
            /* [in] */ ULONG line,
            /* [retval][out] */ ULONG *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IImgObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IImgObject * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IImgObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IImgObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IImgObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IImgObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IImgObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IImgObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Width )( 
            IImgObject * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Height )( 
            IImgObject * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Deepth )( 
            IImgObject * This,
            /* [retval][out] */ ULONG *pVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Pixel )( 
            IImgObject * This,
            /* [in] */ ULONG x,
            /* [in] */ ULONG y,
            /* [retval][out] */ ULONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Pixel )( 
            IImgObject * This,
            /* [in] */ ULONG x,
            /* [in] */ ULONG y,
            /* [in] */ ULONG newVal);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ImageLineAddress )( 
            IImgObject * This,
            /* [in] */ ULONG line,
            /* [retval][out] */ ULONG *pVal);
        
        END_INTERFACE
    } IImgObjectVtbl;

    interface IImgObject
    {
        CONST_VTBL struct IImgObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IImgObject_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IImgObject_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IImgObject_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IImgObject_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IImgObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IImgObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IImgObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IImgObject_get_Width(This,pVal)	\
    ( (This)->lpVtbl -> get_Width(This,pVal) ) 

#define IImgObject_get_Height(This,pVal)	\
    ( (This)->lpVtbl -> get_Height(This,pVal) ) 

#define IImgObject_get_Deepth(This,pVal)	\
    ( (This)->lpVtbl -> get_Deepth(This,pVal) ) 

#define IImgObject_get_Pixel(This,x,y,pVal)	\
    ( (This)->lpVtbl -> get_Pixel(This,x,y,pVal) ) 

#define IImgObject_put_Pixel(This,x,y,newVal)	\
    ( (This)->lpVtbl -> put_Pixel(This,x,y,newVal) ) 

#define IImgObject_get_ImageLineAddress(This,line,pVal)	\
    ( (This)->lpVtbl -> get_ImageLineAddress(This,line,pVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IImgObject_INTERFACE_DEFINED__ */



#ifndef __DetectorLibLib_LIBRARY_DEFINED__
#define __DetectorLibLib_LIBRARY_DEFINED__

/* library DetectorLibLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_DetectorLibLib;

#ifndef ___ISocketChannelEvents_DISPINTERFACE_DEFINED__
#define ___ISocketChannelEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ISocketChannelEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__ISocketChannelEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0F83023B-805A-4A9C-8D72-E684E229C215")
    _ISocketChannelEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ISocketChannelEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ISocketChannelEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ISocketChannelEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ISocketChannelEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ISocketChannelEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ISocketChannelEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ISocketChannelEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ISocketChannelEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ISocketChannelEventsVtbl;

    interface _ISocketChannelEvents
    {
        CONST_VTBL struct _ISocketChannelEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ISocketChannelEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ISocketChannelEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ISocketChannelEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ISocketChannelEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ISocketChannelEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ISocketChannelEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ISocketChannelEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ISocketChannelEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_SocketChannel;

#ifdef __cplusplus

class DECLSPEC_UUID("10F87131-B7BC-4185-8CB8-31CC3C60577C")
SocketChannel;
#endif

#ifndef ___IEngineEvents_DISPINTERFACE_DEFINED__
#define ___IEngineEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IEngineEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IEngineEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E9687DF0-B2DF-4C05-B6C6-6EA90CBD15E6")
    _IEngineEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IEngineEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IEngineEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IEngineEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IEngineEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IEngineEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IEngineEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IEngineEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IEngineEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IEngineEventsVtbl;

    interface _IEngineEvents
    {
        CONST_VTBL struct _IEngineEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IEngineEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IEngineEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IEngineEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IEngineEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IEngineEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IEngineEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IEngineEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IEngineEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Engine;

#ifdef __cplusplus

class DECLSPEC_UUID("20DCFF7C-A385-41D6-B258-C0D4CCC55C95")
Engine;
#endif

#ifndef ___ICmdCoderDTEvents_DISPINTERFACE_DEFINED__
#define ___ICmdCoderDTEvents_DISPINTERFACE_DEFINED__

/* dispinterface _ICmdCoderDTEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__ICmdCoderDTEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("BD9FA336-671F-499A-9FFB-0288ADC24DD8")
    _ICmdCoderDTEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ICmdCoderDTEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ICmdCoderDTEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ICmdCoderDTEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ICmdCoderDTEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ICmdCoderDTEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ICmdCoderDTEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ICmdCoderDTEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ICmdCoderDTEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _ICmdCoderDTEventsVtbl;

    interface _ICmdCoderDTEvents
    {
        CONST_VTBL struct _ICmdCoderDTEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ICmdCoderDTEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ICmdCoderDTEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ICmdCoderDTEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ICmdCoderDTEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ICmdCoderDTEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ICmdCoderDTEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ICmdCoderDTEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ICmdCoderDTEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CmdCoderDT;

#ifdef __cplusplus

class DECLSPEC_UUID("E0D8E9B5-B982-4863-A506-3B2B3BBD716D")
CmdCoderDT;
#endif

EXTERN_C const CLSID CLSID_CmdController;

#ifdef __cplusplus

class DECLSPEC_UUID("C172B127-87DD-49EB-8638-B9E8DB4F5E2D")
CmdController;
#endif

#ifndef ___IImgControllerEvents_DISPINTERFACE_DEFINED__
#define ___IImgControllerEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IImgControllerEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IImgControllerEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("4B563493-9C79-45E5-BD37-BCEB3644129A")
    _IImgControllerEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IImgControllerEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IImgControllerEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IImgControllerEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IImgControllerEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IImgControllerEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IImgControllerEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IImgControllerEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IImgControllerEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IImgControllerEventsVtbl;

    interface _IImgControllerEvents
    {
        CONST_VTBL struct _IImgControllerEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IImgControllerEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IImgControllerEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IImgControllerEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IImgControllerEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IImgControllerEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IImgControllerEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IImgControllerEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IImgControllerEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ImgController;

#ifdef __cplusplus

class DECLSPEC_UUID("7AE0CEC0-6577-4F66-AD83-198782B9E0FC")
ImgController;
#endif

EXTERN_C const CLSID CLSID_ImgCoder;

#ifdef __cplusplus

class DECLSPEC_UUID("9D27632C-BC4A-40D6-86B9-A081BB352002")
ImgCoder;
#endif

#ifndef ___IImgDisplayEvents_DISPINTERFACE_DEFINED__
#define ___IImgDisplayEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IImgDisplayEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IImgDisplayEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0434EF0D-E7D4-4276-BE58-296B994C5C8A")
    _IImgDisplayEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IImgDisplayEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IImgDisplayEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IImgDisplayEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IImgDisplayEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IImgDisplayEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IImgDisplayEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IImgDisplayEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IImgDisplayEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IImgDisplayEventsVtbl;

    interface _IImgDisplayEvents
    {
        CONST_VTBL struct _IImgDisplayEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IImgDisplayEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IImgDisplayEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IImgDisplayEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IImgDisplayEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IImgDisplayEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IImgDisplayEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IImgDisplayEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IImgDisplayEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ImgDisplay;

#ifdef __cplusplus

class DECLSPEC_UUID("5DC9AE41-0C25-4F75-BA53-734A8F0E6394")
ImgDisplay;
#endif

#ifndef ___IImgObjectEvents_DISPINTERFACE_DEFINED__
#define ___IImgObjectEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IImgObjectEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IImgObjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("09AD259C-FAA0-434A-B2B0-E26EEA9E8F3B")
    _IImgObjectEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IImgObjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IImgObjectEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IImgObjectEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IImgObjectEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IImgObjectEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IImgObjectEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IImgObjectEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IImgObjectEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _IImgObjectEventsVtbl;

    interface _IImgObjectEvents
    {
        CONST_VTBL struct _IImgObjectEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IImgObjectEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IImgObjectEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IImgObjectEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IImgObjectEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IImgObjectEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IImgObjectEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IImgObjectEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IImgObjectEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ImgObject;

#ifdef __cplusplus

class DECLSPEC_UUID("0CF690E8-286B-4483-B84A-488327104BAE")
ImgObject;
#endif
#endif /* __DetectorLibLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


