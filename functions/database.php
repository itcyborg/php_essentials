<?php
/**
 * Created by PhpStorm.
 * User: itcyb
 * Date: 5/24/2017
 * Time: 9:53 PM
 */

require_once "Db_connector.inc";
$db = new Db_connector();
$db->isDelete();
$db->setTable("admin");
$data = array(
    'name' => 'user',
    'id' => '10',
    'password' => '12345'
);
$db->setCondition("id='1'");
$db->setData($data);
$db->construct();
echo $db->getQuery();