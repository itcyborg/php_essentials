<?php
/**
 * Created by PhpStorm.
 * User: itcyb
 * Date: 5/27/2017
 * Time: 8:22 AM
 */

if (file_exists("functions/Db_connector.inc")) {
    require "functions/Db_connector.inc";
} else {
    die("Error loading some classes. Class file not found");
}

if (file_exists("functions/upload.inc")) {
    require "functions/upload.inc";
} else {
    die("Error loading some classes. Class file not found");
}

if (file_exists("functions/prettyExceptions.inc")) {
    require "functions/prettyExceptions.inc";
} else {
    die("Error loading some classes. Class file not found");
}