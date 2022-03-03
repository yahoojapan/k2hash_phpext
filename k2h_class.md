---
layout: contents
language: en-us
title: K2hash Class
short_desc: K2HASH PHP Extension - PHP Extension library for K2HASH
lang_opp_file: k2h_classja.html
lang_opp_word: To Japanese
prev_url: constants.html
prev_string: Constants
top_url: developer.html
top_string: Developer
next_url: k2hq_class.html
next_string: K2hQueue Class
---

# K2hash Class
K2hash class provides methods to operation for [K2HASH](https://k2hash.antpick.ax/).  
See each method pages for details.   

## Class overview
```
K2hash {
    public addAttr ( string $key , string $attrkey , string $attrval ) : bool
    public addAttrCryptPass ( string $encpass [, bool $is_default_encrypt ] ) : bool
    public addAttrPluginLib ( string $libfile ) : bool
    public addSubkey ( string $key , string $subkey ) : bool
    public addSubkeys ( string $key , array $subkeys ) : bool
    public cleanCommonAttribute ( void ) : bool
    public close ([ int $waitms ] ) : bool
    public static create ( string $filepath [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] ) : bool
    public disableTransaction ( void ) : bool
    public dumpElementtable ([ mixed $output ] ) : bool
    public dumpFull ([ mixed $output ] ) : bool
    public dumpFullKeytable ([ mixed $output ] ) : bool
    public dumpHead ([ mixed $output ] ) : bool
    public dumpKeytable ([ mixed $output ] ) : bool
    public enableTransaction ([ string $transfile [, string $prefix [, string $param [, int $expire ]]]] ) : bool
    public getAttrInfos ([ mixed $output ] ) : bool
    public arrayfalsegetAttrs ( string $key )
    public stringfalsegetAttrValue ( string $key , string $attrkey )
    public getAttrVersionInfos ([ mixed $output ] ) : bool
    public getIterator ( string $key ) : mixed
    public getKeyQueue ([ bool $is_filo [, string $prefix ]] ) : mixed
    public getQueue ([ bool $is_filo [, string $prefix ]] ) : mixed
    public getStream ( string $key , string $mode ) : mixed
    public arrayfalsegetSubkeys ( string $key [, bool $attrcheck ] )
    public static getTransactionThreadPool ( void ) : int
    public stringfalsegetValue ( string $key [, string $subkey [, bool $attrcheck [, string $pass ]]] )
    public loadArchive ( string $filepath [, bool $errskip ] ) : bool
    public open ( string $filepath , bool $readonly [, bool $removefile [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]]] ) : bool
    public openMem ([ int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]] ) : bool
    public openRO ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] ) : bool
    public openRW ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] ) : bool
    public openTempfile ( string $filepath [, bool $fullmap [, int $maskbitcnt [, int $cmaskbitcnt [, int $maxelementcnt [, int $pagesize ]]]]] ) : bool
    public printState ([ mixed $output ] ) : bool
    public static printVersion ([ mixed $output ] ) : bool
    public putArchive ( string $filepath [, bool $errskip ] ) : bool
    public remove ( string $key [, string $subkey ] ) : bool
    public removeAll ( string $key ) : bool
    public rename ( string $key , string $newkey ) : bool
    public setCommonAttribute ([ int $is_mtime [, int $is_history [, int $is_encrypt [, string $passfile [, int $is_expire [, int $expire ]]]]]] ) : bool
    public static setTransactionThreadPool ( int $count ) : bool
    public setValue ( string $key , string $value [, string $subkey [, string $pass [, int $expire ]]] ) : bool
    public transaction ( bool $enable [, string $transfile [, string $prefix [, string $param [, int $expire ]]]] ) : bool
    public static unsetTransactionThreadPool ( void ) : bool
}
```

## Method list

- [K2hash::addAttr](k2h_addattr.html) - Adds the attribute to the key
- [K2hash::addAttrCryptPass](k2h_addattrcryptpass.html) - Adds the password to encrypt values
- [K2hash::addAttrPluginLib](k2h_addattrpluginlib.html) - Adds the user-defined library to handle attributes
- [K2hash::addSubkey](k2h_addsubkey.html) - Associates the key with the other key
- [K2hash::addSubkeys](k2h_addsubkeys.html) - Adds the subkeys to the key
- [K2hash::cleanCommonAttribute](k2h_cleancommonattribute.html) - Initializes the common attributes
- [K2hash::close](k2h_close.html) - Closes the k2h file
- [K2hash::create](k2h_create.html) - Creates the k2h file
- [K2hash::disableTransaction](k2h_disabletransaction.html) - Stops a transaction
- [K2hash::dumpElementtable](k2h_dumpelementtable.html) - Prints elements of the k2hash's hash table elements
- [K2hash::dumpFull](k2h_dumpfull.html) - Prints the k2hash's hash tables in details
- [K2hash::dumpFullKeytable](k2h_dumpfullkeytable.html) - Prints details of the k2hash's hash tables
- [K2hash::dumpHead](k2h_dumphead.html) - Prints the k2hash's headers
- [K2hash::dumpKeytable](k2h_dumpkeytable.html) - Prints the k2hash's hash tables
- [K2hash::enableTransaction](k2h_enabletransaction.html) - Starts a transaction
- [K2hash::getAttrInfos](k2h_getattrinfos.html) - Prints the attribute information
- [K2hash::getAttrs](k2h_getattrs.html) - Gets attributes of the key
- [K2hash::getAttrValue](k2h_getattrvalue.html) - Gets an attribute value of the attribute key of the key
- [K2hash::getAttrVersionInfos](k2h_getattrversioninfos.html) - Prints the attribute library version
- [K2hash::getIterator](k2h_getiterator.html) - Gets a K2hIterator object
- [K2hash::getKeyQueue](k2h_getkeyqueue.html) - Gets a K2hKeyQueue object
- [K2hash::getQueue](k2h_getqueue.html) - Gets a K2hQueue object
- [K2hash::getStream](k2h_getstream.html) - Gets a k2hash file stream
- [K2hash::getSubkeys](k2h_getsubkeys.html) - Gets an array of keys associated with the key
- [K2hash::getTransactionThreadPool](k2h_gettransactionthreadpool.html) - Gets the number of transaction workers
- [K2hash::getValue](k2h_getvalue.html) - Gets the value associated with the key
- [K2hash::loadArchive](k2h_loadarchive.html) - Loads data from the file
- [K2hash::open](k2h_open.html) - Opens the k2h file
- [K2hash::openMem](k2h_openmem.html) - Attaches k2hash data segments on memory
- [K2hash::openRO](k2h_openro.html) - Read the k2hash file
- [K2hash::openRW](k2h_openrw.html) - Edit the k2hash file
- [K2hash::openTempfile](k2h_opentempfile.html) - Edit the k2hash file on temporary file system
- [K2hash::printState](k2h_printstate.html) - Prints k2hash data statistics
- [K2hash::printVersion](k2h_printversion.html) - Prints the k2hash library version
- [K2hash::putArchive](k2h_putarchive.html) - Saves data as the archive file
- [K2hash::remove](k2h_remove.html) - Removes the key
- [K2hash::removeAll](k2h_removeall.html) - Removes the key and the keys associated with the key
- [K2hash::rename](k2h_rename.html) - Renames the key
- [K2hash::setCommonAttribute](k2h_setcommonattribute.html) - Sets the common attributes
- [K2hash::setTransactionThreadPool](k2h_settransactionthreadpool.html) - Sets the number of transaction workers
- [K2hash::setValue](k2h_setvalue.html) - Sets the value associated with the key
- [K2hash::transaction](k2h_transaction.html) - Changes transaction settings
- [K2hash::unsetTransactionThreadPool](k2h_unsettransactionthreadpool.html) - Stops transaction workers
