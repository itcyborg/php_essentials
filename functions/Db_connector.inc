<?php

/**
 * Created by PhpStorm.
 * User: itcyb
 * Date: 5/24/2017
 * Time: 9:20 PM
 */
class Db_connector
{
    private $table;
    private $details;
    private $msg;
    private $error;
    private $columns;
    private $values;
    private $data;
    private $connection_info;
    private $insert;
    private $update;
    private $delete;
    private $select;
    private $create;
    private $query;
    private $condition;


    /**
     * Db_connector constructor.
     */
    public function __construct()
    {
        $this->table = "";
        $this->details = null;
        $this->msg = null;
        $this->error = false;
        $this->columns = array();
        $this->values = array();
        $this->data = array();
        $this->connection_info = null;
        $this->insert = false;
        $this->update = false;
        $this->delete = false;
        $this->select = false;
        $this->create = false;
        $this->query = null;
        $this->condition = "";
    }

    #Setters

    /**
     * @param string $table
     * @return Db_connector
     */
    public function setTable(string $table): Db_connector
    {
        $this->table = $table;
        return $this;
    }

    /**
     * @param null $details
     * @return Db_connector
     */
    public function setDetails($details)
    {
        $this->details = $details;
        return $this;
    }

    /**
     * @param array $data
     * @return Db_connector
     */
    public function setData(array $data): Db_connector
    {
        $this->data = $data;
        return $this;
    }

    /**
     * @param bool $update
     * @return Db_connector
     */
    public function isUpdate(): Db_connector
    {
        $this->update = true;
        return $this;
    }

    /**
     * @param bool $delete
     * @return Db_connector
     */
    public function isDelete(): Db_connector
    {
        $this->delete = true;
        return $this;
    }

    /**
     * @param bool $select
     * @return Db_connector
     */
    public function isSelect(): Db_connector
    {
        $this->select = true;
        return $this;
    }

    /**
     * @param bool $insert
     * @return Db_connector
     */
    public function isInsert(): Db_connector
    {
        $this->insert = true;
        return $this;
    }

    /**
     * @param string $condition
     */
    public function setCondition(string $condition)
    {
        $this->condition = $condition;
    }


    /**
     * @return null
     */
    public function getMsg()
    {
        return $this->msg;
    }

    /**
     * @return bool
     */
    public function isError(): bool
    {
        return $this->error;
    }

    /**
     * @return null
     */
    public function getConnectionInfo()
    {
        return $this->connection_info;
    }

    /**
     * @return null
     */
    public function getQuery()
    {
        return $this->query;
    }

    public function construct()
    {
        if ($this->table !== null && $this->table !== "") {
            if (sizeof($this->data) > 0) {
                foreach ($this->data as $column => $value) {
                    $this->columns[] = $column;
                    $this->values[] = $value;
                }
                $this->set();
            } else {
                $this->error = true;
                $this->msg = "No data has been received";
                #throw error
            }
        } else {
            #throw error
            $this->msg = "No table has been declared";
            $this->error = true;
        }
    }

    function set()
    {
        #insert query
        if ($this->insert) {
            $fields = "";
            $count = 0;
            $vals = "";
            foreach ($this->columns as $column) {
                if ($count == 0) {
                    $fields = $column;
                    $vals = "'" . $this->values[$count] . "'";
                } else {
                    $fields .= "," . $column;
                    $vals .= ",'" . $this->values[$count] . "'";
                }
                $count++;
            }
            $query = "INSERT INTO $this->table ($fields) VALUES ($vals)";
            $this->query = $query;
        }

        #select query
        if ($this->select) {
            $fields = "";
            $count = 0;
            foreach ($this->columns as $column) {
                if ($count == 0) {
                    $fields = $this->table . "." . $column;
                } else {
                    $fields .= "," . $this->table . "." . $column;
                }
                $count++;
            }
            $query = "SELECT $fields FROM $this->table WHERE $this->condition";
            $this->query = $query;
        }

        #update query
        if ($this->update) {
            $count = 0;
            $vals = "";
            foreach ($this->columns as $column) {
                if ($count == 0) {
                    $vals = "SET $column= '" . $this->values[$count] . "'";
                } else {
                    $vals .= ",$column= '" . $this->values[$count] . "'";
                }
                $count++;
            }
            $query = "UPDATE $this->table $vals WHERE $this->condition";
            $this->query = $query;
        }

        #delete query
        if ($this->delete) {
            $query = "DELETE FROM $this->table WHERE $this->condition";
            $this->query = $query;
        }
    }
}