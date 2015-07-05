# coding: utf-8
# @author (2015-07-04) Yuuya Miyamae
class ApplicationController < ActionController::Base
  protect_from_forgery with: :exception
  include SessionsHelper
end
