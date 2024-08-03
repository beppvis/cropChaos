#include "items.h"


Color getItemColor(Item item)
{
  if (item.itemType == Bread.itemType){
    return BROWN;
  }
  return RED;
}
