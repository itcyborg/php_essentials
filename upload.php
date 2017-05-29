<?php
/**
 * Created by PhpStorm.
 * User: itcyb
 * Date: 5/23/2017
 * Time: 11:59 AM
 */

//add the class
require_once "autoload.php";
//create a new instance of the class
$upload = new Upload();
try {
    //pass the file variable ($_FILES['file'])
    $upload->setFile($_FILES['file']);

    //set a list of allowed file types(optional)
    //$upload->setAllowed(array('pdf', 'txt'));

    //set the maximum file size allowed in bytes(optional)
    $upload->setMaxSize(1000000000);

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

    //get the url of the file after a successful file upload
    echo $upload->getFilename() . "<br>";
    //get the response
    echo $upload->getMsg();
} catch (pExceptions $e) {
    die($e);
}

