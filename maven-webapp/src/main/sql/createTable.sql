DROP TABLE nametable;

CREATE TABLE `test`.`nametable` (
  `name` VARCHAR(30) NOT NULL,
  `age` INT NULL,
  `salary` DECIMAL NULL,
  `phonenumber` VARCHAR(20) NULL,
  `email` VARCHAR(45) NULL,
  `password` VARCHAR(10) NULL,
  PRIMARY KEY (`name`));
  
INSERT INTO `test`.`nametable` (`name`, `age`, `salary`, `phonenumber`, `email`, `password`) VALUES ('zhangsan', '20', '2000', '18288883377', 'zhangsan@163.com', '123456');
INSERT INTO `test`.`nametable` (`name`, `age`, `salary`, `phonenumber`, `email`, `password`) VALUES ('张三', '31', '6000', '13800001111', 'zs@198.com', '333444');
  