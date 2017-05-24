<?php
/**
 * Created by PhpStorm.
 * User: itcyb
 * Date: 5/23/2017
 * Time: 11:59 AM
 */

//add the class
require_once "upload.inc";
//create a new instance of the class
$upload = new Upload();
try {
    //pass the file variable ($_FILES['file'])
    $upload->setFile($_FILES['file']);

    //set a list of allowed file types
    $upload->setAllowed(array('pdf', 'txt'));

    $upload->setMaxSize(2048);

    //finish the configurations
    $upload->setAll();

    //get the file size
    //$upload->getSize();

    //get the file extension
    //$upload->getExt();

    //get status message: errors and status
    //$upload->getMsg();

    //upload the file
    $upload->up();
    echo $upload->getMsg();
} catch (UploadException $e) {
    die($e);
}

