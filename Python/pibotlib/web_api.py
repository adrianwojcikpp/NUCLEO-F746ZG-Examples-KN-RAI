import requests

class PiBot:
    def __init__(self, ip_address):
        self.ip_address = ip_address
        self.protocol = 'http://'
        self.pwm_control_url = self.protocol + self.ip_address + '/' + 'pwm_write.php'
        self.make_photo_url  = self.protocol + self.ip_address + '/' + 'cgi-bin' + '/' + 'aruco_code.py'

    def set_motors(self, motor_rigth, motor_left):
        duty = {'duty1': str(motor_rigth), 'duty2': str(motor_left)}
        r = requests.get(self.pwm_control_url, params=duty)
        print(r.content)

    def make_photo(self):
        r = requests.get(self.make_photo_url)
        print(r.content)
