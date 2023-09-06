

import os
import getpass
import argparse

class Option(object):

    _default_option = { 'environ': 'dev', 'verbose': False,
                        'force': False,
                        'start_date': None, 'end_date': None, 
                        'tickers': None, 'port_name': None
                       }

    def __init__(self, name = None, user = None, args = None):

        self.name = name
        self.user = user
        self.cli_args = vars(args) if args is not None else {}
        
        # set defaults
        for k, v in Option._default_option.items():
            setattr(self, k, v)

        for k, v in self.cli_args.items():
            print(k, v)
            setattr(self, k, v)
            

        if self.name is None:
            self.name = 'standard'
            
        if self.user is None:
            self.user = getpass.getuser()


def get_default_parser():
    #
    parser = argparse.ArgumentParser()
    parser.add_argument('--environ', dest='environ', default='dev', help='runtime environment')
    parser.add_argument('--verbose', action='store_true', dest='verbose', default=False, help='verbose')
    parser.add_argument('--user', dest='user', default=None, help='user name')        
    parser.add_argument('--force', action='store_true', dest='force', default=False, help='verbose')
    
    parser.add_argument('--start_date', dest='start_date', default="2013-01-01", help='start date (YYYY-MM-DD)')
    parser.add_argument('--end_date', dest='end_date', default="2024-01-01", help='end date (YYYY-MM-DD)')
    parser.add_argument('--tickers', dest='tickers', default=None, help='Tickers with | separator')
    
    return(parser)
            
def _test():

    parser = get_default_parser()
    parser.add_argument('--foo', dest='foo', default = 'whatever', help='a parameter')
    parser.add_argument('--apikey', dest='api_key_file', help='a parameter')        

    args = parser.parse_args()
    
    opt = Option(args = args)
    print (opt.name, opt.user, opt.force, opt.start_date, opt.foo, opt.api_key_file)

    
    opt = Option()
    print (opt.name, opt.user, opt.force, opt.start_date, opt.tickers)

    opt = Option(name = "yahoo applicaiton",  user = "John Doe")
    print (opt.name, opt.user, opt.force, opt.start_date, opt.tickers)
    
    

if __name__ == "__main__":
    _test()
