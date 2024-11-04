#!/bin/sh
ifconfig | grep -Eoi '[a-z0-9]{2}(:[a-z0-9]{2}){5}'
