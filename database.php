<?php
/**
 * Created by PhpStorm.
 * User: itcyb
 * Date: 5/24/2017
 * Time: 9:53 PM
 */

$db = new PDO("mysql:host=$host;dbname=$dbname", $dbuser, $dbpass, $options);
try {
    $db->query();
} catch (PDOException $e) {
    die($e->getMessage());
}

//add the class and create a new instance
require_once "autoload.php";
$db = new Db_connector();

//set the type of query you want to run
#insert
//$db->isInsert();
#update
//$db->isUpdate();
#delete
//$db->isDelete();
#select
$db->isSelect();

//set the table
$db->setTable("admin");

//pass the database details
$db->setDetails(array('host' => 'localhost', 'dbname' => 'fine', 'dbpass' => '', 'dbuser' => 'root', 'port' => '3306', 'showerrors' => false));

//set the data in an associative array with column name as key and value as value to be inserted
$data = array(
    'name' => 'Dominic',
    'email' => 'dominic@email.com',
    'id' => '121',
    'password' => '12345'
);

//set the conditions if is update,delete or select query
//$db->setCondition("id='1'");

//pass the data
$db->setData($data);

//execute the query and get the response
$res = $db->exec();

//check for messages
echo $db->getMsg();

//view the response
die($res);