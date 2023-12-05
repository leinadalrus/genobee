#if _WIN32 || __linux__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif

#ifdef _WIN32
#include <initguid.h>
#include <io.h>

#include <ntddk.h>
#include <ntintsafe.h>

#include <wdf.h>
#include <wdfusb.h>
#endif // _WIN32

#ifdef __linux__
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/usb.h>
#endif // __linux__

#ifdef ALLOC_PRAGMA
#pragma alloc_text(INIT, DriverEntry)
#endif // ALLOC_PRAGMA

NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT DriverObject,
                     _In_ PUNICODE_STRING RegistryPath) {
  WDF_DRIVER_CONFIG config;
  NTSTATUS status;

  WDF_DRIVER_CONFIG_INIT(&config, UsbEventDeviceAdd);

  status = WdfDriverCreate(DriverObject, RegistryPath, WDF_NO_OBJECT_ATTRIBUTES,
                           &config, WDF_NO_HANDLE);

  return status;
}

namespace {
int probe(struct usb_interface *interface, struct usb_device_id const *id);
int probe(struct usb_interface *interface, struct usb_device_id const *id) {
  struct usb_device *device = nullptr;
  struct usb_host_interface *interf_desc = interface->cur_altsetting;
  struct usb_endpoint_descriptor *endpt_desc;

  device = interface_to_usbdev(interface);
  return 0;
}

void disconnect(struct usb_interface *interface);

struct usb_device_id usb_device_id_table[] = {
  { USB_DEVICE(0x0, 0x0) },
  {} /* Terminating entry */
};

struct usb_driver _usb_device_driver = {
  .name = "mapsysvad",
  .probe = probe,
  .disconnect = disconnect,
  .id_table = usb_device_id_table
};

int init(void *user_data);
int init(void *user_data) {
  return usb_register(&_usb_device_driver);
}

void exit(void *exit_table);
void exit(void *exit_table) {
  usb_deregister(&_usb_device_driver);
}
} // namespace
