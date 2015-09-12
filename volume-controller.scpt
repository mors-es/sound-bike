
set onMode to false
set use_port to "/dev/cu.usbmodemfa131"

repeat until (get serialport list) contains use_port
	delay 3
end repeat

if (get serialport list) contains use_port then

	set onMode to true
	
	set myPort to serialport open use_port bps rate 9600 data bits 8 parity 0 stop bits 1 handshake 0

	delay 1

	if myPort is equal to -1 then
		display dialog "could not open port"
	else
		repeat while onMode is true
			set x to serialport read myPort
			set curVolume to output volume of (get volume settings)
			if x is not equal to "" then
				--beep
				if x is equal to "A" then
					--display dialog "Success"
					set volume output volume ((output volume of (get volume settings)) + 1.5) --100%
					--tell application "iTunes" to play (next track)
				end if

				if x is equal to "B" and curVolume > 20 then
					--display dialog "Success"
					set volume output volume ((output volume of (get volume settings)) - 4) --100%
				end if
				--if x is equal to "A" and curVolume > 70 then
				--	set volume output volume ((output volume of (get volume settings)) + 4) --100%
				--end if
				if x is equal to "C" and curVolume > 70 then
					--display dialog "Success"
					set volume output volume ((output volume of (get volume settings)) - 2) --100%
				end if
				if x = "q" then
					display dialog "Quitting"
					serialport close myPort
					exit repeat
				end if
			end if
		end repeat
	end if
	serialport close myPort

end
