create table Address
(
    id        int auto_increment
        primary key,
    street    varchar(255) default '' not null,
    city      varchar(32)  default '' not null,
    area_code int                     not null,
    state     varchar(32)  default '' not null
);

create table Contact
(
    id           int auto_increment
        primary key,
    phone_number int         not null,
    email        varchar(64) not null
);

create table UserAccount
(
    id         int auto_increment
        primary key,
    username   varchar(16) not null,
    password   varchar(32) not null,
    address_id int         null,
    contact_id int         not null,
    constraint UserLogin_Password_uindex
        unique (password),
    constraint UserLogin_Username_uindex
        unique (username),
    constraint address
        foreign key (address_id) references Address (id),
    constraint contact
        foreign key (contact_id) references Contact (id)
);

