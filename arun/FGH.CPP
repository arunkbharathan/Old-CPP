 #include <bios.h>
#include <stdio.h>

int main(void)
{
  struct diskinfo_t dinfo;
  int result;
  static char dbuf[512];

  dinfo.drive =  0;    /* drive number for A: */
  dinfo.head  =  0;    /* disk head number */
  dinfo.track =  0;    /* track number */
  dinfo.sector  =  1;  /* sector number */
  dinfo.nsectors =  1; /* sector count */
  dinfo.buffer = dbuf; /* data buffer */

  printf("Attempting to read from drive A:\n");
  result = _bios_disk(_DISK_READ, &dinfo);
  if ((result & 0xff00) == 0)
  {
    printf("Disk read from A: successful.\n");
    printf("First three bytes read are 0x%02x 0x%02x 0x%02x\n",
      dbuf[0] & 0xff, dbuf[1] & 0xff, dbuf[2] & 0xff);
  }
  else
    printf("Cannot read drive A, status = 0x%02x\n", result);
  return 0;
}

