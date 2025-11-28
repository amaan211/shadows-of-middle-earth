QT = core

CONFIG += c++17 cmdline

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
SOURCES += \
    # src/Armour.cpp \
    # src/Inventory.cpp \
    src/Armour.cpp \
    src/CharacterSpecials.cpp \
    src/Inventory.cpp \
    src/Item.cpp \
    # src/ItemFactory.cpp \
    # src/Ring.cpp \
    # src/Shield.cpp \
    src/ItemFactory.cpp \
    src/Ring.cpp \
    src/Shield.cpp \
    src/Weapon.cpp \
    src/main.cpp \
    # src/Game.cpp \
    # src/Board.cpp \
    # src/Square.cpp \
    # src/Character.cpp \
    # src/Human.cpp \
    # src/Elf.cpp \
    # src/Dwarf.cpp \
    # src/Hobbit.cpp \
    # src/Orc.cpp \
    # src/Item.cpp \
    # src/Weapon.cpp \
    # src/Armour.cpp \
    # src/Shield.cpp \
    # src/Ring.cpp \
    # src/Inventory.cpp \
    # src/Combat.cpp

# HEADERS += \
#     src/Game.h \
#     src/Board.h \
#     src/Square.h \
#     src/Character.h \
#     src/Human.h \
#     src/Elf.h \
#     src/Dwarf.h \
#     src/Hobbit.h \
#     src/Orc.h \
#     src/Item.h \
#     src/Weapon.h \
#     src/Armour.h \
#     src/Shield.h \
#     src/Ring.h \
#     src/Inventory.h \
#     src/Combat.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    src/Armour.h \
    src/Armour.h \
    src/Character.h \
    src/Inventory.h \
    src/Inventory.h \
    src/Item.h \
    src/ItemFactory.h \
    src/ItemFactory.h \
    src/Ring.h \
    src/Ring.h \
    src/Shield.h \
    src/Shield.h \
    src/Weapon.h
